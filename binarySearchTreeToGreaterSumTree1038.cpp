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
    vector<TreeNode*>nodes;
    void go (TreeNode*& n) {
        if (!n) return;
        go (n->right);
        nodes.push_back(n);
        //cout << n->val <<", ";
        go (n->left);
        //n->val+=sum;
        return;
    }
    TreeNode* bstToGst(TreeNode* root) {
        go (root);
        int prev = 0;
        for (int i = 1; i < nodes.size(); i++) {
            nodes[i]->val += nodes[i-1]->val;
        }
        return root;
    }
};
