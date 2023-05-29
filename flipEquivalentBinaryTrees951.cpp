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
    unordered_map<int, int>parent;
    bool ans = true;
    int count = 0;
    void go (TreeNode*& n, int p) {
        if (!n) return;
        parent[n->val] = p;
        go (n->left, n->val);
        go (n->right, n->val);
        count++;
    }
    void verify(TreeNode*& n, int p) {
        if (!n || !ans) return;
        count--;
        if (parent[n->val] != p) {
            ans = false;
            return;
        }
        verify (n->left, n->val);
        verify (n->right, n->val);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        go (root1, -1);
        verify(root2, -1);
        return ans && !count;
    }
};
