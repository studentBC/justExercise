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
    void findHeight(TreeNode* node, int& height, int& deep) {
        if (!node)return;
        height++;
        findHeight(node->left,height,deep);
        findHeight(node->right,height, deep);
        if (height > deep) deep = height;
        height--;
        return;
    }
    void go (TreeNode* node, bool& ans) {
        if (!node || !ans)return;
        int height = 0, left = 0, right = 0;
        findHeight(node->left,height, left);
        height = 0;
        findHeight(node->right, height, right);
        if (abs(left-right) > 1) ans = false;
        go(node->left,ans);
        go(node->right,ans);
        return;
    }
    bool isBalanced(TreeNode* root) {
        /*
        int height = 0, left = 0, right = 0;
        findHeight(root->left,height, left);
        height = 0;
        findHeight(root->right, height, right);
        if (abs(left-right) > 1) return false;
        */
        bool ans = true;
        go(root,ans);
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int getHeight(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        
        int leftHeight = node->left ? getHeight(node->left) : 0;
        int rightHeight = node->right ? getHeight(node->right) : 0;
        
        return 1 + max(leftHeight, rightHeight);
    }
    
    bool isBalanced(TreeNode* node) {
        if (node == NULL) {
            return true;
        }
        
        int leftHeight = node->left ? getHeight(node->left) : 0;
        int rightHeight = node->right ? getHeight(node->right) : 0;
        bool rootIsBalanced = abs(leftHeight - rightHeight) <= 1;
        
        return rootIsBalanced && isBalanced(node->left)
                              && isBalanced(node->right);
    }
};
