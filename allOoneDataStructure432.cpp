class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        data.clear();
		big = INT_MIN; small = INT_MAX;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto it = data.find(key);
		if (it == data.end()) {
			data.insert(pair<string,int>(key,1));
		} else {
			it->second++;
		}
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
		auto it = data.find(key);
		if (it != data.end()) {
			if (it->second == 1) {
				data.erase(key);
			} else {
				it->second--;
			}
		}
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
		string ans;
		int big = INT_MIN;
        for (auto it:data) {
			if (big < it.second) {
				big = it.second;
				ans = it.first;
			}
		}
		return ans;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
    	int small = INT_MAX;  
		string ans;
		for (auto it:data) {
			if (small > it.second) {
				small = it.second;
				ans = it.first;
			}
		}
		return ans;
    }
private:
	map<string,int>data;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
//the fatest method
using namespace std;
class BucketNode;

class PayloadNode {
public:
	string key;
	PayloadNode* prev;
	PayloadNode* next;

	BucketNode* bucket;

	PayloadNode(string key, BucketNode* bucket) {
		this->key = key;
		this->bucket = bucket;
        prev = next = nullptr;
	}

	pair<BucketNode*, BucketNode*> moveBucket(bool left);
};

class BucketNode {
public:
	int value;
	BucketNode* prev;
	BucketNode* next;

	PayloadNode* begin;
	PayloadNode* end;

	BucketNode(int value) {
		this->value = value;
        prev = next = nullptr;
		begin = end = nullptr;
	}
};

pair<BucketNode*, BucketNode*> PayloadNode::moveBucket(bool left) {
	// detach from current bucket
	BucketNode* currentBucket = bucket;
	if (this->prev != nullptr) {
		this->prev->next = this->next;
	}
	if (this->next != nullptr) {
		this->next->prev = this->prev;
	}
	if (currentBucket->begin == this) {
		currentBucket->begin = this->next;
	}
	if (currentBucket->end == this) {
		currentBucket->end = this->prev;
	}
	prev = next = nullptr;
	BucketNode* maxBucket = nullptr;
	BucketNode* minBucket = nullptr;
	BucketNode* dstBucket = nullptr;
	if (left) {
		if (currentBucket->prev == nullptr || currentBucket->prev->value != currentBucket->value + 1) {
			dstBucket = new BucketNode(currentBucket->value + 1);
			if (currentBucket->prev != nullptr) {
				currentBucket->prev->next = dstBucket;
				dstBucket->prev = currentBucket->prev;
			} else {
				maxBucket = dstBucket;
			}
			currentBucket->prev = dstBucket;
			dstBucket->next = currentBucket;
		} else {
			dstBucket = currentBucket->prev;
		}
	}
	if (!left) {
		if (currentBucket->next->value != currentBucket->value - 1) {
			dstBucket = new BucketNode(currentBucket->value - 1);
			dstBucket->prev = currentBucket;
			dstBucket->next = currentBucket->next;
			currentBucket->next->prev = dstBucket;
			currentBucket->next = dstBucket;
		}
		// we always have right bucket
		dstBucket = bucket->next;
	}
	// attach to the dst-bucket, append to the end
	if (dstBucket->end != nullptr) {
		dstBucket->end->next = this;
		prev = dstBucket->end;
	}
	dstBucket->end = this;
	if (dstBucket->begin == nullptr) {
		dstBucket->begin = this;
	}
	bucket = dstBucket;
	// if current bucket(!= 1, != 0) is empty, kill it
	if (currentBucket->value != 1 && currentBucket->value != 0 && currentBucket->begin == nullptr) {
		if (currentBucket->prev == nullptr) { // i am the current max bucket
			maxBucket = currentBucket->next;
		}
		if (currentBucket->prev != nullptr) {
			currentBucket->prev->next = currentBucket->next;
		}
		if (currentBucket->next != nullptr) {
			currentBucket->next->prev = currentBucket->prev;
		}
		delete currentBucket;
	}
	return make_pair(maxBucket, minBucket);
}

class AllOne {
private:
	BucketNode* number1Bucket;
	BucketNode* number0Bucket;
	BucketNode* maxBucket;
	BucketNode* minBucket;
	map<string, PayloadNode*>* payloads;
public:
	/** Initialize your data structure here. */
	AllOne() {
		number1Bucket = new BucketNode(1);
		number0Bucket = new BucketNode(0);
		number1Bucket->next = number0Bucket;
		number0Bucket->prev = number1Bucket;
		maxBucket = minBucket = number1Bucket;
		payloads = new map<string, PayloadNode*>();
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		PayloadNode* node = nullptr;
		auto ite = payloads->find(key);
		if (ite == payloads->end()) {
			// create a payload node to number 0 bucket
			node = new PayloadNode(key, number0Bucket);
		} else {
			node = ite->second;
		}
		(*payloads)[key] = node;
		// move this node to left bucket
		pair<BucketNode*, BucketNode*> moveResult = node->moveBucket(true);
		if (moveResult.first != nullptr) {
			maxBucket = moveResult.first;
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		auto ite = payloads->find(key);
		if (ite == payloads->end()) return;
		PayloadNode* node = ite->second;
		if (node->bucket->value == 0) return;
		pair<BucketNode*, BucketNode*> moveResult = node->moveBucket(false);
		if (moveResult.first != nullptr) {
			maxBucket = moveResult.first;
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (maxBucket->begin == nullptr) return "";
		return maxBucket->begin->key;
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (number1Bucket->begin != nullptr) {
			return number1Bucket->begin->key;
		}
		if (number1Bucket->prev == nullptr) return "";
		return number1Bucket->prev->begin->key;
	}
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
