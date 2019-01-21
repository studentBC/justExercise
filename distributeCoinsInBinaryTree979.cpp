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
    void goImplement (TreeNode* node, int step, int&move, bool& found) {
        if (!node || found)return;
        if (node->val == 0 && !found) {
            node->val++;
            found = true;
            move+=step;
            return;
        }
        goImplement (node->left,step+1,move,found);
        goImplement (node->right,step+1,move,found);
    }
    void goNimplement (TreeNode* node, int&move, int step) {
        //cout << node->val << ":  ";
        if (node->left && node->left->val >1) {
            move+=(node->left->val-1);
            node->val+=(node->left->val-1);
            node->left->val = 1;
        }
        if (node->right&&node->right->val >1) {
            move+=(node->right->val-1);
            node->val+=(node->right->val-1);
            node->right->val = 1;
        }
        bool found = false;
        while (node->val >1) {
                step = 0;found = false;
                goImplement(node,step,move,found);
                if (found) {
                    node->val--;
                } else {
                    break;
                }
        }
        //cout << node->val << endl;
        return;
    }
    void gather (TreeNode* node, int&move, int step) {
        if (!node)return;
        //goNimplement(node,move,0);
        gather (node->left,move,step+1);
        //goNimplement(node,move,0);
        
        gather (node->right,move,step+1);
        goNimplement(node,move,0);
        
    }

    int distributeCoins(TreeNode* root) {
        int move = 0 , step = 0;bool found = false;

        //gather all the coin to root
        gather(root,move,step);
        //cout<<move <<endl;
        //distribute all the coin
        /*
        while (root->val >1) {
                step = 0;found = false;
                goImplement(root,step,move,found);
                root->val--;
                move+=step;
        }
        */
        //implement(root,step,move);
        //go (root,move,step,found);
        return move;
    }
};

