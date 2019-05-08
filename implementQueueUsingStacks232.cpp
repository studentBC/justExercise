class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        start = 0;
        mq.clear();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        mq.emplace_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        start++;
        return mq[start-1];
    }
    
    /** Get the front element. */
    int peek() {
        return mq[start];
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (start >= mq.size() || mq.empty()) {
            return true;
        } else {
            return false;
        }
    }

private:
    vector<int>mq;
    int start;
}; 

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
