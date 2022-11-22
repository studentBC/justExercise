/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //left, right, result
    vector<int>go(TreeNode* n) {
        if (!n) return {-1, -1, -1};
        vector<int>left = go (n->left), right = go(n->right);
        int ans = max(max(left[1], right[0])+1, max(left[2], right[2]));
        return {left[1]+1, right[0]+1, ans};
    }
    int longestZigZag(TreeNode* root) {
        return go(root)[2];
    }
};
