/*
Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

Example 1:

Input:
        1
       / \
      2   3
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
 

Example 2:

Input:
        2
       / \
      1   3
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
 

Note: All the values of tree nodes are in the range of [-1e7, 1e7].




 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void go (TreeNode* node, int length, unordered_map<TreeNode *, TreeNode *>& nodes, int& ans, int delta) {
        if (!node) return;
        ans = max (ans, length);
        //cout << node->val <<" -> ";
        if (node->left && node->left->val == node->val+delta) go (node->left, length+1, nodes, ans, delta);
        if (node->right && node->right->val == node->val+delta) go (node->right, length+1, nodes, ans, delta);
        if (nodes[node] && nodes[node]->val == node->val+delta) go (nodes[node], length+1, nodes, ans, delta);
    }
    void traverse (TreeNode* node, TreeNode* parent, unordered_map<TreeNode *, TreeNode *>& nodes) {
        if (!node) return;
        nodes[node] = parent;
        traverse(node->left, node, nodes);
        traverse(node->right, node, nodes);
    }
    int longestConsecutive(TreeNode* root) {
        unordered_map<TreeNode *, TreeNode *>node;
        traverse(root, nullptr, node);        
        int ans = 0;
        for (auto& it: node) {
            //cout <<endl << "increasing .... " << endl;
            go (it.first, 1, node, ans, 1);
            //cout <<endl << "decreasing .... " << endl;
            go (it.first, 1, node, ans, -1);
        }
        return ans;
    }
};
//the fatest solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        dfs(root, root, longest);
        return longest;
    }

    pair<int, int> dfs(TreeNode * node, TreeNode * parent, int & longest) {
        if ( NULL == node ) {
            return make_pair(0, 0);
        }
        auto left = dfs(node->left, node, longest);
        auto right = dfs(node->right, node, longest);
        longest = max(longest, left.first + right.second + 1);
        longest = max(longest, left.second + right.first + 1);
        int inc = 0, dec = 0;
        if ( node->val == parent->val + 1 ) {
            inc = max(left.first, right.first) + 1;
        }
        if ( node->val == parent->val - 1 ) {
            dec = max(left.second, right.second) + 1;
        }
        return make_pair(inc, dec);
    }
};
