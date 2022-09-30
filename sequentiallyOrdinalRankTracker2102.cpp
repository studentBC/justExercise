/*
 We can use a similar approach as an optimization to avoid repeated sorting.
Employ two heaps: left heap and right heap. The left heap is a max-heap, and the right heap is a min-heap. The size of the left heap is k + 1 (best locations), where k is the number of times the get method was invoked. The other locations are maintained in the right heap.
Every time when add is being called, we add it to the left heap. If the size of the left heap exceeds k + 1, we move the head element to the right heap.
When the get method is invoked again (the k + 1 time it is invoked), we can return the head element of the left heap. But before returning it, if the right heap is not empty, we maintain the left heap to have the best k + 2 items by moving the best location from the right heap to the left heap.
 */

typedef pair<int, string> pd;
class SORTracker {
public:
    int index = 0;
    // Structure of the condition
    // for sorting the pair by its
    // second elements
    struct smaller {
        constexpr bool operator()(
            pair<int, string>& a,
            pair<int, string>& b)
            //const noexcept
        {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
    struct bigger {
        constexpr bool operator()(
            pair<int, string>& a,
            pair<int, string>& b)
            //const noexcept
        {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    priority_queue<pd, vector<pd>, smaller> left;
    priority_queue<pd, vector<pd>, bigger> right;
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        left.push({score, name});
        if (left.size() > index+1) {
            //cout <<"pop " << left.top().second << endl;
            right.push(left.top());
            left.pop();
        } 
    }
    
    string get() {
        string ans = left.top().second;
        if (!right.empty()) {
            //cout <<"pop " << right.top().second << endl;
            left.push(right.top());
            right.pop();
        }
        index++;
        return ans;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
