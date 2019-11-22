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
    void get (TreeNode* node, int high, int& height) {
        if (!node) return;
        height = max (high, height);
        get (node->left, high+1, height);
        get (node->right, high+1, height);
    }
    void go (int left, int right, int high, TreeNode* node, vector<vector<string>>& ans) {
        if (!node) return;
        int mid = (right+left)/2;
        ans[high][mid] = to_string(node->val);
        go (left, mid-1, high+1, node->left, ans);
        go (mid+1, right, high+1, node->right, ans);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>>ans;
        if (!root) return ans;
        int height = 0, total;
        get (root, 1, height);
        total = pow(2, height) -1;
        //cout << height <<" , " << total << endl;
        for (int i = 0; i < height; i++) {
            vector<string>temp(total, "");
            ans.emplace_back(temp);
        }
        go (0, total-1, 0, root, ans);
        return ans;
    }
};

