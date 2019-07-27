/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Consider the following binary search tree: 

     5
    / \
   2   6
  / \
 1   3
Example 1:

Input: [5,2,6,1,3]
Output: false
Example 2:

Input: [5,2,1,3,6]
Output: true

wrong test case:
[1,3,2]
[2,3,1]
*/
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return true;
        vector<int>node;int lower = INT_MIN;
        node.emplace_back(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            if (lower > preorder[i]) return false;
            if (preorder[i] < node.back()) {
                node.emplace_back(preorder[i]);
            } else {
                while (!node.empty() && node.back() < preorder[i]) {
                    lower = max (node.back(), lower);
                    node.pop_back();
                }
                node.emplace_back(preorder[i]);
            }
        }
        return true;
    }
};
//the fatest method
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        stack<int> sk;
        
        for(int n: preorder) {
            if(n < low) return false;
            while(!sk.empty() && n > sk.top()) {
                low = sk.top();
                sk.pop();
            }

            sk.push(n);
        }
        return true;
    }
};

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
