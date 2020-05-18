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
    void go (TreeNode* node, int big, int& ans) {
        if (!node) return;
        if (node->val >= big) ans++;
        big = max (node->val, big);
        go (node->left, big, ans);
        go (node->right, big, ans);
        return;
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        go (root, -100000, ans);
        return ans;
    }
};
//132 ms solution
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
    int ans=0;
    void preorder(TreeNode* root,int max)
    {  if(root==NULL)
             return ;
     if(root->val>=max)
     {
         ans++;
         max=root->val;
     }
        preorder(root->left,max);
     preorder(root->right,max);
    }
    int goodNodes(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int max=root->val;
        preorder(root,max);
        return ans;
    }
};
