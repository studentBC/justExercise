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
    void go (TreeNode* t, string& ans) {
        if (!t)return;
        ans+=to_string(t->val);
        if (t->right || t->left) {
            ans+="(";
            go (t->left,ans);
            ans+=")";
        }
        if (t->right) {
            ans+="(";
            go (t->right,ans);
            ans+=")";
        }
    }
    string tree2str(TreeNode* t) {
        string ans = "";
        go (t,ans);
        return ans;
    }
};
