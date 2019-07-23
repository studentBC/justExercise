/*
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:

MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:

-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
*/
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        num.clear();
    }

    void push(int x) {
        num.emplace_back(x);
    }

    int pop() {
        int ans = num.back();
        num.pop_back();
        return ans;
    }

    int top() {
        return num.back();
    }

    int peekMax() {
        int big = INT_MIN;
        for (int i:num) {
            if (big < i) {
                big = i;
            }
        }
        return big;
    }

    int popMax() {
        int big = INT_MIN, index = -1;
        for (int i = 0; i < num.size(); i++) {
            if (big <= num[i]) {
                big = num[i];
                index = i;
            }
        }
        num.erase(num.begin()+index);
        return big;
    }
private:
    vector<int>num;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
//the fatest method
class MaxStack {
public:
  void push(int x) {
    max.insert(val.insert(val.cend(), x));
  }

  int pop() {
    int result = val.back();
    max.erase(prev(max.upper_bound(prev(val.cend()))));
    val.pop_back();
    return result;
  }

  int top() {
    return val.back();
  }

  int peekMax() {
    return **max.rbegin();
  }

  int popMax() {
    int result = **max.rbegin();
    val.erase(*max.rbegin());
    max.erase(prev(max.cend()));
    return result;
  }
  
private:
  using Iterator = list<int>::const_iterator;
  
  struct IteratorComparison { bool operator()(Iterator a, Iterator b) const { return *a < *b; } };
  
  list<int>                              val;
  multiset<Iterator, IteratorComparison> max;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

static auto const magic = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
