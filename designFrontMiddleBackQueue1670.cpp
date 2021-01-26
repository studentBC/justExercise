class FrontMiddleBackQueue {
public:
    vector<int>ans;
    int tmp, mid;
    FrontMiddleBackQueue() {
        ans.clear();
    }

    void pushFront(int val) {
        ans.insert(ans.begin(), val);
    }

    void pushMiddle(int val) {
        mid = ans.size() / 2;
        ans.insert(ans.begin() + mid, val);
    }

    void pushBack(int val) {
        ans.push_back(val);
    }

    int popFront() {
        if(ans.empty()) return -1;
        tmp = ans[0];
        ans.erase(ans.begin());
        return tmp;
    }

    int popMiddle() {
        if(ans.empty()) return -1;
        if (ans.size() % 2)mid = ans.size() / 2;
        else mid = ans.size() / 2 - 1;
        tmp = ans[mid];
        ans.erase(ans.begin()+mid);
        return tmp;
    }

    int popBack() {
        if(ans.empty()) return -1;
        tmp = ans.back();
        ans.pop_back();
        return tmp;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
//180 ms solution
class FrontMiddleBackQueue {
    deque<int> v;
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        v.push_front(val);
    }
    
    void pushMiddle(int val) {
        deque<int> tmp;
        int n = v.size();
        int index = n / 2;
        for(int i = 0;i < index;++i)
            tmp.push_back(v[i]);
        tmp.push_back(val);
        for(int i = index;i < n;++i)
            tmp.push_back(v[i]);
        v = tmp;
    }
    
    void pushBack(int val) {
        v.push_back(val);
    }
    
    int popFront() {
        if(v.empty())
            return -1;
        int ret = v.front();
        v.pop_front();
        return ret;
    }
    
    int popMiddle() {
        if(v.empty())
            return -1;        
        deque<int> tmp;
        int n = v.size();
        int index = 0;
        index = n / 2;
        if(n % 2 == 0)
            --index;
        for(int i = 0;i < index;++i)
            tmp.push_back(v[i]);
        int ret = v[index];
        for(int i = index + 1;i < n;++i)
            tmp.push_back(v[i]);
        v = tmp;
        return ret;
    }
    
    int popBack() {
        if(v.empty())
            return -1;
        int ret = v.back();
        v.pop_back();
        return ret;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
