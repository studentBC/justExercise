/*
Given the root of a binary tree, return the number of uni-value 
subtrees
.

A uni-value subtree means all nodes of the subtree have the same value.
*/

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
private:
    int cnt = 0;
    bool dfs(TreeNode* root){
        if(!root) return true;
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        if(left and right){
            if(root->left and root->left->val != root->val)
                return false;
            if(root->right and root->right->val != root->val)
                return false;
            cnt++;
            return true;
        }
        return false;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};
