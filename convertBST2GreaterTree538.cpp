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
    void go (TreeNode* node , int& accumulate) {
        if (!node)return;
        go (node->right, accumulate);
        accumulate+=node->val;
        node->val = accumulate;
        go (node->left, accumulate);
        return;
    }
    TreeNode* convertBST(TreeNode* root) {
        int accumulate = 0;
        go (root, accumulate);
        return root;
    }
};
//the fatest method
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (not root) return nullptr;
        int sum = 0;
        vector<TreeNode*> stk = {root};
        auto node = root;
        do {
            while (stk.back()->right) stk.emplace_back(stk.back()->right);
            do {      
                node = stk.back();
                sum += node->val;
                node->val = sum;
                stk.pop_back();
                if (node->left) {
                    stk.emplace_back(node->left);
                    break;
                }
            } while (not stk.empty());
        } while (not stk.empty());
        return root;
    }
};
