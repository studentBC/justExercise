/**
 * Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:

Input: [[1,1],2,[1,1]]
Output: 8
Explanation: Four 1's at depth 1, one 2 at depth 2.

Example 2:

Input: [1,[4,[6]]]
Output: 17
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17.


 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    void go (NestedInteger nes, vector<pair<int,int>>& value, int dep, int& deepest) {
        deepest = max (deepest, dep);
        if (nes.isInteger()) {
            value.emplace_back(pair<int,int>(nes.getInteger(), dep));
        } else {
            vector<NestedInteger>neslist = nes.getList();
            for (int i = 0; i < neslist.size(); ++i) {
                go (neslist[i], value, dep+1, deepest);
            }
        }
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<pair<int,int>>value;
        int deepest = -1, ans = 0;
        for (int i = 0; i < nestedList.size(); ++i) {
            go (nestedList[i],value,0,deepest);
        }
        deepest++;
        for (int i = 0; i < value.size(); i++) {
            ans+=value[i].first*(deepest-value[i].second);
        }
        return ans;
    }
};
//the fatest method
class Solution {
private:
    void helper(vector<NestedInteger>& nestedList, vector<int>& flatten, int i) {
        if (flatten.size() < i) {
            flatten.resize(i);
        }
        int val = 0;
        for (auto&& item : nestedList) {
            if (item.isInteger()) {
                val += item.getInteger();
            } else {
                helper(item.getList(), flatten, i + 1);
            }
        }
        flatten[i - 1] += val;
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> flatten;
        helper(nestedList, flatten, 1);
        int i = flatten.size(), ans = 0;
        for (auto&& v : flatten) {
            ans += v * i--;
        }
        return ans;
    }
};
