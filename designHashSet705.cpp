class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        us.clear();
    }
    
    void add(int key) {
        us.insert(key);
    }
    
    void remove(int key) {
        us.erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return us.find(key) != us.end();
    }
private:
    unordered_set<int>us;
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
//the fatest method
class MyHashSet {
    private:
    vector<bool> dp;
public:
    /** Initialize your data structure here. */
    MyHashSet():dp(vector<bool>(1000001, false)){
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    }
    void add(int key) {
        dp[key] = true;
    }
    void remove(int key) {
        dp[key] = false;
    }
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return dp[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
