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
    unordered_set<int>del;
    unordered_map<int, TreeNode*>n;
    unordered_set<TreeNode*>ans;
    void go (TreeNode*& node) {
        if (!node) return;
        n[node->val] = node;
        if (del.count(node->val)) {
            if (node->left) ans.insert(node->left);
            if (node->right) ans.insert(node->right);
        }
        go (node->left);
        go (node->right);
        if (del.count(node->val)) node = NULL;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        del = unordered_set<int>(to_delete.begin(), to_delete.end());
        go (root);
        if (root&&!del.count(root->val))ans.insert(root);
        for (int i : to_delete) {
            ans.erase(n[i]);
        }
        vector<TreeNode*>lol(ans.begin(), ans.end());
        return lol;
    }
};
