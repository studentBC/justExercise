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
    bool check (unordered_map<int,int>& path) {
        int even = 0, odd = 0; long total;
        for (auto& it: path) {
            //cout << it.first <<" , " << it.second << endl;
            if (it.second%2) odd++;
            else even++;
            total+=it.second;
            if (odd > 1) return false;
        }
        //cout << endl;
        if (total%2) {
            if (odd == 1) return true;
            else return false;
        } else {
            if (odd) return false;
            else return true;
        }
    }
    void go (TreeNode* node, unordered_map<int,int>& path, int& ans) {
        path[node->val]++;
        if (node->left == NULL && node->right == NULL) {
            if (check(path))ans++;
            path[node->val]--;
            return;
        }
        if (node->left) {
            go (node->left, path, ans);
        }
        if (node->right) {
            go (node->right, path, ans);
        }
        path[node->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>path;
        int ans = 0;
        if (!root) return 0;
        go (root, path, ans);
        return ans;
    }
};
//148 ms solution
int result = []() { ios::sync_with_stdio(false); cin.tie(0); return 0; }();

inline void countPaths(TreeNode* root, int cur) {
    cur ^= 1 << root->val;
    if (root->left) { countPaths(root->left, cur); if (root->right) countPaths(root->right, cur); }
    else if (root->right) countPaths(root->right, cur);
    else result += (cur & (cur-1)) == 0;
}

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        result = 0;
        countPaths(root, 0);        
        return result;
    }
};
