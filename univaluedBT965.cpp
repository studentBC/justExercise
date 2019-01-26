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
    void go (TreeNode* node, int& prev, bool& ans) {
        if (!node || !ans)return;
        if (node->val!=prev) {
            ans = false;
        }
        go(node->left,prev,ans);
        go(node->right,prev,ans);
    }
    bool isUnivalTree(TreeNode* root) {
        if (!root)return true;
        bool ans = true;
        go(root,root->val,ans);
        return ans;
    }
};
