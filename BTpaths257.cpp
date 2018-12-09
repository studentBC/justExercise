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
    void go(TreeNode* node, vector<vector<int>>&all, vector<int>&one) {
        if (!node)return;
        one.push_back(node->val);
        go(node->left,all,one);
        go(node->right,all,one);
        if (!node->left && !node->right)all.push_back(one);
        one.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>>all;
        vector<int>one;
        vector<string>ans;
        go (root,all,one);
        string path;
        for (int i = 0; i< all.size(); i++) {
            path = "";
            for (int j = 0; j < all[i].size(); j++) {
                path+=to_string(all[i][j]);
                if (j!=all[i].size()-1)
                path+="->";
            }
            ans.push_back(path);
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return {};
        string p(to_string(root->val));
        vector<string> res;
        if (root->left == NULL && root->right == NULL) {res.push_back(p);return res;}
        if (root->left != NULL) helper(root->left, res, p);
        if (root->right != NULL) helper(root->right, res, p);
        return res;
    }
    
    void helper(TreeNode* r, vector<string>& res, string p) {
        p+=("->"+to_string(r->val));
        if (r->left == NULL && r->right == NULL) {res.push_back(p);return;}
        
        if (r->left != NULL) helper(r->left, res, p);
        if (r->right != NULL) helper(r->right, res, p);
    }
};

