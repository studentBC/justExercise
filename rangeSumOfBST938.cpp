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
    void go (TreeNode* node, int& sum, int l, int r) {
        if (!node)return;
        if (node->val >= l && node->val <= r) {
            sum+=node->val;
        }
        go (node->left,sum,l,r);
        go (node->right,sum,l,r);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        go (root,sum,L,R);
        return sum;
    }
};
//the fatest method
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int L, int R)
    {
        if (!root) return;
        if (root->val >= L && root->val <= R)
        {
            ans += root->val;
            dfs(root->left, L, R);
            dfs(root->right, L, R);
        }
        else if (root->val > R)
            dfs(root->left, L, R);
        else
            dfs(root->right, L, R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        dfs(root, L, R);
        return ans;
    }
};
