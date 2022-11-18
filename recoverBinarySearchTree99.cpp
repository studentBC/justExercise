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
    vector<int>rule;
    void go (TreeNode*& n) {
        if(!n) return;
        go (n->left);
        nodes.push_back(n);
        rule.push_back(n->val);
        go (n->right);
    }
    void recoverTree(TreeNode* root) {
        go (root);
        sort(rule.begin(), rule.end());
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->val != rule[i]) {
                nodes[i]->val = rule[i];
            }
        }
        return;
        
    }
};
