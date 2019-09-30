class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (data.empty()) {
            data.emplace_back(num);
            return;
        } else if (data[0] >= num) {
            data.insert(data.begin(), num);
            return;
        } else if (data.back() <= num) {
            data.emplace_back(num);
            return;
        }
        //int end = data.size()-1;
        for (int i = 1; i < data.size(); i++) {
            if (num >= data[i-1] && num <= data[i]) {
                data.insert(data.begin()+i, num);
                return;
            }
        }
    }
    
    double findMedian() {
        int mid = data.size()>>1;
        if (data.size()%2) {
            return data[mid];
        } else {
            return (double)(data[mid]+data[mid-1])/2;
        }
    }
private:
    vector<int>data;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    //Always let minHeap.size() <= maxHeap.size()
    void addNum(int num) {
        if(maxHeap.empty()){
            maxHeap.push(num);
        }
        else if(maxHeap.size() == minHeap.size()){
            if(num >= minHeap.top()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }
        else{
            if(num >= maxHeap.top()){
                minHeap.push(num);
            }
            else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
    }

    double findMedian() {
        if(maxHeap.size() != minHeap.size()){
            return maxHeap.top();
        }
        else{
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }

private:
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
