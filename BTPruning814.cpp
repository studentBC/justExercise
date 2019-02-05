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
    void check (TreeNode** node, bool& contain) {
        if (!*node || contain)return;
        if ((*node)->val == 1) {
            contain= true;
            return;
        }
        check (&((*node)->left),contain);
        check (&((*node)->right),contain);
    }
    void go (TreeNode** node,bool& contain) {
        if (!*node)return;
        //cout << (*node)->val << endl;
        contain = false;
        check (node,contain);
        if (!contain) {
            cout << (*node)->val << endl;
            *node = NULL;
            return;
        }
        //if ((*node)->left)cout <<"go left " <<(*node)->left->val << endl;
        go (&((*node)->left), contain);
        //if ((*node)->right)cout <<"go right  " << (*node)->right->val << endl;
        go (&((*node)->right), contain);
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool contain = false;
        TreeNode** node = &root;
        //cout << (*node)->val << endl;
        go (node,contain);
        return root;
    }
};
