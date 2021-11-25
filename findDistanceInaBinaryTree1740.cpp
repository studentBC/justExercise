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
    void go (TreeNode* node, TreeNode* p) {
        if (!node) return;
        if (p) parent[node->val] = p->val;
        else parent[node->val] = -1;
        go (node->left, node);
        go (node->right, node);
    }
    void find (int p, vector<int>& path) {
        while (p > -1) {
            path.push_back(p);
            p = parent[p];
        }
    }
    int findDistance(TreeNode* root, int p, int q) {
        go (root, NULL);
        vector<int>p1, p2;
        find(p, p1);
        find(q, p2);
        int c = 0;
        for (int i = p1.size()-1, j = p2.size()-1; i > -1 && j > -1; i--, j--) {
            if (p1[i] == p2[j]) {
                c++;
            } else {
                break;
            }
        }
        return p1.size() + p2.size() - c -c;
        return 0;
    }
};
