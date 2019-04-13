class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        nums.clear();
        return;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (nums.count(val) == 0) {
            nums.insert(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (nums.count(val) == 0) {
            return false;
        } else {
            nums.erase(val);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        std::uniform_int_distribution<int> dis(0,nums.size()-1);
        int temp = dis(gen) , i = 0;
        for (auto it = nums.begin(); it!= nums.end(); it++) {
            if (i == temp) return *it;
            i++;
        }
        return *nums.begin();
    }
private:
    set<int>nums;
    std::random_device rd;
    std::default_random_engine gen = std::default_random_engine(rd());
};
//the fatest method
class RandomizedSet {
    default_random_engine seed;
    vector<int> values;
    unordered_map<int, int> x2i;
public:
    /** Initialize your data structure here. */
    RandomizedSet() : seed(random_device()()) {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto p = x2i.emplace(val, x2i.size());
        if (p.second) {
            values.emplace_back(val);
        }
        return p.second;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = x2i.find(val);
        if (it == x2i.end()) return false;
        int y = values.back();
        values[it->second] = y;
        values.pop_back();
        x2i[y] = it->second;
        x2i.erase(it);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int i = uniform_int_distribution<int>{0, values.size() - 1}(seed);
        return values[i];
    }
};
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
