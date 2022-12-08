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
    unordered_map<int, unordered_set<int>>graph;
    unordered_set<int>visited;
    int ans = 0;
    bool found = false;
    void go (TreeNode* n, TreeNode* p) {
        if (!n) return;
        if (p) graph[n->val].insert(p->val);
        if (n->left) graph[n->val].insert(n->left->val);
        if (n->right) graph[n->val].insert(n->right->val);
        go (n->left, n);
        go (n->right, n);
    }
    void goo (int s, int t, int dist) {
        if (found || visited.count(s)) return;
        if (s == t) {
            ans = dist;
            found = true;
        }
        visited.insert(s);
        for (int i : graph[s]) goo(i, t, dist+1);
    }
    int findDistance(TreeNode* root, int p, int q) {
        go (root, nullptr);
        goo (p, q, 0);
        return ans;
    }
};
