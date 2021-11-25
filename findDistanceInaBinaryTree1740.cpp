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

//24 ms solution
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
private:
    int _lca(TreeNode* root, int& p, int& q, TreeNode** lca) {
        if (root == NULL) return 0;
        if (*lca != NULL) return 0;
        int ret = 0;
        if (root->val == p || root->val == q) ++ret;
        ret += _lca(root->left, p, q, lca);
        ret += _lca(root->right, p, q, lca);
        if (ret == 2 && *lca == NULL) *lca = root;
        return ret;
    }
    bool _path(TreeNode* root, int& target, vector<int>& path) {
        if (root == NULL) return false;
        if (root->val == target) {
            path.push_back(target);
            return true;
        }
        if (_path(root->left, target, path)) {
            path.push_back(root->val);
            return true;
        }
        if (_path(root->right, target, path)) {
            path.push_back(root->val);
            return true;
        }
        return false;
    }
    int _distance(TreeNode* root, int a, int b) {
        if (root == NULL) return 0;
        int dist_to_a = -1, dist_to_b = -1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (a == cur->val) dist_to_a = dist;
            if (b == cur->val) dist_to_b = dist;
            if (dist_to_a >= 0 && dist_to_b >= 0) break;
            if (cur->left) q.push({cur->left, dist + 1});
            if (cur->right) q.push({cur->right, dist + 1});
        }
        return dist_to_a + dist_to_b;
    }
public:
    int findDistance(TreeNode* root, int p, int q) {
        if (p == q) return 0;
        if (root == NULL) return 0;
        TreeNode* lca = NULL;
        _lca(root, p, q, &lca);
        // cout << "lca is " << lca->val << "\n";
        // vector<int> path;
        // _path(lca, p, path);
        //_path(lca, q, path);
        // for (auto n : path) cout << n << ",";
        // return path.size();
        return _distance(lca, p, q);
    }
};
