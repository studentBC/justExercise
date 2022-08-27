class RLEIterator {
public:
    vector<int>num;
    
    RLEIterator(vector<int>& encoding) {
        num = encoding;
    }
    
    int next(int n) {
        // 
        while (n && !num.empty()) {
            if (num[0] > n) {
                num[0]-=n;
                return num[1];
            } else if (num[0] == n) {
                int tmp = num[1];
                num.erase(num.begin());
                num.erase(num.begin());
                return tmp;
            } else {
                n-=num[0];
                num.erase(num.begin());
                num.erase(num.begin());
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
