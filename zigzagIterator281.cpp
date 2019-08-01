/*
Given two 1d vectors, implement an iterator to return their elements alternately.

Example:

Input:
v1 = [1,2]
v2 = [3,4,5,6] 

Output: [1,3,2,4,5,6]

Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,3,2,4,5,6].
Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question:
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:

Input:
[1,2,3]
[4,5,6,7]
[8,9]

Output: [1,4,8,2,5,9,3,6,7].
*/
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        for (int i : v1)q1.push(i);
        for (int i : v2)q2.push(i);
        turn = true;
    }

    int next() {
        int ans;
        if (turn && !q1.empty() || q2.empty()) {
            ans = q1.front();
            q1.pop();
            turn = false;
        } else {
            ans = q2.front();
            q2.pop();
            turn = true;
        }
        return ans;
    }

    bool hasNext() {
        return !q1.empty() || !q2.empty();
    }
private:
    queue<int>q1, q2;
    bool turn;
};
/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
//the fatest method
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.size()> 0)
        q.emplace(make_pair(v1.begin(), v1.end()));
        if (v2.size() > 0)
        q.emplace(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        auto iter_pair = q.front();
        q.pop();
        int r = *(iter_pair.first);
        iter_pair.first++;
        if (iter_pair.first != iter_pair.second) {
            q.emplace(iter_pair);
        }
        return r;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
    queue<pair<std::vector<int>::iterator,  std::vector<int>::iterator>> q;
};
/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
