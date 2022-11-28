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
    unordered_map<int, int>level;
    unordered_map<int, int>parent;
    void go (TreeNode* n, int l, int p) {
        if (!n) return;
        level[n->val] = l;
        parent[n->val] = p;
        go (n->left, l+1, n->val);
        go (n->right, l+1, n->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        go (root, 0, -1);
        return level[x] == level[y] && parent[x]!=parent[y];
    }
};
