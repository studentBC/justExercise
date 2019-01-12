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
    void go(TreeNode* node, int sum, int target, vector<int>&temp, vector<vector<int>>&ans) {
        if (!node)return;
        sum+=node->val;
        temp.push_back(node->val);
        if (sum == target && node->left == NULL && node->right == NULL) {
            ans.push_back(temp);
        }
        go (node->left,sum,target,temp,ans);
        go (node->right,sum,target,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>temp;
        vector<vector<int>>ans;
        go(root,0,sum,temp,ans);
        return ans;
    }
};
