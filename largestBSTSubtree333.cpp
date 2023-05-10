/*
Given the root of a binary tree, find the largest 
subtree
, which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.

A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:

The left subtree values are less than the value of their parent (root) node's value.
The right subtree values are greater than the value of their parent (root) node's value.
Note: A subtree must include all of its descendants.
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
public:
    int dfs(TreeNode *node, int &ans){
        if(!node) return 0;
        int l = dfs(node->left, ans), r = dfs(node->right, ans);
        TreeNode *lc = node->left, *rc = node->right;
        if(lc){
            while(lc->right) lc = lc->right;
            if(!(lc->val < node->val)) return -1;
        }
        if(rc){
            while(rc->left) rc = rc->left;
            if(!(node->val < rc->val)) return -1;
        }
        if(l == -1 || r == -1) return -1;
        ans = max(ans, l + r + 1);
        return l + r + 1;
    }
    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
