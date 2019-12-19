/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.

Example 1:

Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.

Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.

*/
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
    void go (TreeNode* node, int p, int& mm, TreeNode** ans) {
        if (!node) return;
        if (node->val > p && node->val < mm) {
            mm = node->val;
            *ans = node;
        }
        go (node->left, p, mm, ans);
        go (node->right, p, mm, ans);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode** ans = new TreeNode*;
        int mm = INT_MAX;
        go (root,p->val,mm,ans);
        if (mm == INT_MAX) return NULL;
        return *ans;
    }
};
//the fatest method
class Solution {
public:
    void recur(TreeNode* root, TreeNode *p, TreeNode*& res) {
        if (!root) return;
        if (root->left) recur(root->left, p, res);
        if (res) return;
        if (!res && root->val > p->val) {
            res = root;
            return;
        }
        if (root->right) recur(root->right, p, res);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        TreeNode* res = nullptr;
        recur(root, p, res);
        return res;
        
    }
};