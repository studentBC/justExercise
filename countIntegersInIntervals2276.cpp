class CountIntervals {
public:
    map<int, int>interval;
    int c = 0;
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it = interval.upper_bound(left);
        if (it!=begin(interval) && prev(it)->second >= left) it = prev(it);
        for (; it!=interval.end() && it->first <= right; interval.erase(it++)) {
            left = min(left, it->first);
            right = max(right, it->second);
            c -= it->second-it->first+1;
        }
        c+= right-left+1;
        interval[left] = right;
    }
    
    int count() {
        return c;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
