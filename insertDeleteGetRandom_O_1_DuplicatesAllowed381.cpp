class RandomizedCollection {
public:
    default_random_engine seed;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        number.emplace_back(val);
        if (data.find(val)!=data.end()) {
            data[val].emplace_back(number.size()-1);
            return false;
        } else {
            vector<int>temp;
            temp.emplace_back(number.size()-1);
            data[val] = temp;
            return true;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(data.find(val) == data.end()) {
            return false;
        } else {
            number[data[val].back()] = INT_MAX;
            data[val].pop_back();
            if (data[val].size() == 0) {
                data.erase(val);
            }
            return true;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int i = uniform_int_distribution<int>{0, number.size() - 1}(seed);
        while (number[i] == INT_MAX) {
            i = uniform_int_distribution<int>{0, number.size() - 1}(seed);
        }
        return number[i];
    }
private:
    map<int,vector<int>>data;
    vector<int>number;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
//the fatest solution
class RandomizedCollection {
private:
    vector<int> N;
    unordered_multimap<int,int> M;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        std::ios_base::sync_with_stdio(false);
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool ret = (M.count(val) == 0);
        N.push_back(val);
        M.insert({val, N.size()-1});
        
        //printf("insert=%d idx=%d\n", val, N.size()-1);
        return ret;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (M.count(val) == 0) {
            return false;
        }

        auto it = M.find(val);
        int idx = it->second;
        //printf("remove=%d, idx=%d\n", val, idx);
        M.erase(it);
        
        int last_val = N.back();
        //printf("  - erased {%d,%d}, finding %d\n",val,idx,last_val);
        auto lastit = M.find(last_val);
        while (lastit != M.end() && lastit->second != N.size()-1) lastit++;
        if (lastit != M.end()) {
            lastit->second = idx;
            N[idx] = last_val;
        }
        
        N.pop_back();
        //printf("  - N size = %d\n", N.size());
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        //printf("getRandom\n");
        return N[rand() % N.size()];
    }
};


