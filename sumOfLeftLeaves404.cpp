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
    void go (TreeNode* node,int& sum) {
        if (!node)return;
        go (node->left,sum);
        if (node->left) {
            if (!node->left->left && !node->left->right) {
                cout<<node->left->val<<endl;
                sum+=node->left->val;
            }
        }
        go (node->right,sum);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        go (root, sum);
        return sum;
    }
};
//fatest method
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int sum = 0;
        sum += sumOfLeftLeaves(root->left);
        if(root->left && !root->left->left && !root->left->right)
            sum += root->left->val;
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};

