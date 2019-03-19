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
    void getLevel (TreeNode* node, int temp, int& level) {
        if (!node)return;
        if (temp > level) level = temp;
        getLevel(node->left,temp+1,level);
        getLevel(node->right,temp+1,level);
    }
    void go (TreeNode* node, int temp, int& level, bool& ans, bool& trim) {
        if (!node || !ans)return;
        if (temp<level && (!node->left || !node->right)) ans = false;
        if (temp == level && !node->left && node->right) ans = false;
        if (!trim && temp == level && node->left && !node->right) {
            trim = true;
        } else if (!trim && temp == level && !node->left && !node->right) {
            trim = true;
        } else if (temp == level && (node->left || node->right) && trim ) {
            ans = false;
        }
        go (node->left,temp+1,level,ans,trim);
        go (node->right,temp+1,level,ans, trim);
        return; 
    }
    bool isCompleteTree(TreeNode* root) {
        int level = 0;
        getLevel (root,1,level);
        //cout << level << endl;
        bool ans = true, trim = false;
        level--;
        go (root, 1, level, ans, trim);
        return ans;
    }
};


