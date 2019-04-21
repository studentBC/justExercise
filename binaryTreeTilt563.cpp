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
    int ans = 0;
    void getsum (TreeNode* node, int& sum) {
        if (!node)return;
        sum+=node->val;
        getsum(node->left,sum);
        getsum(node->right,sum);
    }
    int findTilt(TreeNode* root) {
        if (!root)return 0;
        int left = findTilt (root->left);
        int right = findTilt (root->right);
        int ls = 0, rs = 0;
        getsum(root->left,ls);
        getsum(root->right,rs);
        ans+=abs(ls - rs);
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int tilt = 0;
    
    int traverse(TreeNode *root) {
        if (!root) return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        tilt += abs(left-right);
        return left + right + root->val;
    }
    
    int findTilt(TreeNode* root) {
        traverse(root);
        return tilt;
    }
};
