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
    void go (TreeNode* node, int val, bool& found) {
        if (!node || found)return;
        if (node->val > val) {
            go (node->left,val,found);
            //cout << node->val <<" , ";
            if (!found) {
                node->left = new TreeNode(val);
                //node->left->val = val;
                found = true;
            }
        } else if (node->val < val) {
            go (node->right,val, found);
            //cout << node->val <<" , ";
            if (!found) {
                node->right = new TreeNode(val);
                //node->right->val = val;
                found = true;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        bool found = false;
        go (root,val,found);
        return root;
    }
};
