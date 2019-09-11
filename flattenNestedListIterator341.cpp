/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    void go (vector<int>& number, NestedInteger ni) {
        if (ni.isInteger()) {
            number.emplace_back(ni.getInteger());
        } else {
            vector<NestedInteger>temp = ni.getList();
            for (int i = 0; i < temp.size(); i++) {
                go (number, temp[i]);
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); i++) {
            go (number, nestedList[i]);
        }
        //for (int i:number) cout <<i <<" , ";
    }

    int next() {
        int n = number[index];
        index++;
        return n;
    }

    bool hasNext() {
       return index != number.size();
    }
private:
    int index = 0;
    vector<int>number;
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
//the fatest solution
class NestedIterator {
public:
    typedef vector<NestedInteger>::iterator iter;  
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }
    int next() {
        return begins.top()++->getInteger();
    }
    bool hasNext() {
        while(begins.size()) {
            iter it = begins.top();
            if(it == ends.top()) {
                begins.pop();
                ends.pop();
                if(!begins.empty()) begins.top()++;
            }
            else if (it->isInteger()) {
                return true;
            }
            else {
                vector<NestedInteger>& lst = it->getList();
                begins.push(lst.begin());
                ends.push(lst.end());
            }
        }
        return false;
    }
private:
   stack<iter> begins, ends;
};

