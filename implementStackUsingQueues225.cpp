class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        vs.clear();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        vs.emplace_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int back = vs.back();
		vs.pop_back();
    }
    
    /** Get the top element. */
    int top() {
        return vs.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return vs.empty();
    }
private:
	vector<int>vs;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        queue<int> tmp;
        while (!data.empty())
        {
            tmp.push(data.front());
            data.pop();
        }
        data.push(x);
        while (!tmp.empty())
        {
            data.push(tmp.front());
            tmp.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = data.front();
        data.pop();
        return val;
    }

    /** Get the top element. */
    int top() {
        return data.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }

private:
    queue<int> data;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
