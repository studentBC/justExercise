class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        c = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (data.size() < c) {
            data.push(value);
            return true;
        } else {
            return false;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (!data.empty()) {
            data.pop();
            return true;
        } else {
            return false;
        }
    }
   
    /** Get the front item from the queue. */
    int Front() {
        if (data.empty()) return -1;
        return data.front();
    }
   
    /** Get the last item from the queue. */
    int Rear() {
        if (data.empty()) return -1;
        return data.back();
    }
   
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return data.empty();
    }
   
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return data.size() == c;
    }
private:
    queue<int>data;
    int c;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
//20 ms solution
class MyCircularQueue {
public:
    //Note: start to end - 1. nums[ end ] is NOT a member.
    MyCircularQueue(int k) {
        //Note: resize, important
        nums.resize( k );
        start = 0;
        end = 0;
        full = false;
    }
    
    bool enQueue(int value) {
        if( full ){ 
            return false;
        }
        nums[ end ] = value;
        end = ( end + 1 ) % nums.size();
        if( end == start ){ 
            full = true;
        }
        return true;
    }
    
    bool deQueue() {
        if( this->isEmpty() ){ 
            return false;
        }
        
        if( full ){ 
            full = false;
        }    
        start = ( start + 1 ) % nums.size();
        return true;
    }
    
    int Front() {
        if( this->isEmpty() ){ 
            return -1;
        }
        return nums[ start ];        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if( this->isEmpty() ){ 
            return -1;
        }
        return nums[ ( end + nums.size() - 1 ) % nums.size() ];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if( !full && start == end ){ 
            return true;
        }
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return full;
    }
    
private: 
    vector< int > nums;
    int start, end;
    bool full;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
