class RangeModule {
public:
    map<int, int> interval;
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto l = interval.upper_bound(left), r = interval.upper_bound(right);
        if (l != interval.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l!=r) {
            left = min(left, l->first);
            right = max(right, (--r)->second);
            interval.erase(l, ++r);
        }
        interval[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = interval.upper_bound(left);
        if (it == interval.begin() || (--it)->second < right) return false;
        return true;
    }
    
    void removeRange(int left, int right) {
        auto l = interval.upper_bound(left), r = interval.upper_bound(right);
        if (l!=interval.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l == r) return;
        int ll = min(left, l->first), rr = max(right, (--r)->second);
        interval.erase(l, ++r);
        if (ll < left) interval[ll] = left;
        if (rr > right) interval[right] = rr;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
