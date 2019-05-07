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
    void checkBig (TreeNode* node, int& target, bool& correct, TreeNode** exchange) {
        if (!node) return;
        if (node->val > target) {
            correct = false;
            target = node->val;
            *exchange = node;
        }
        checkBig (node->left, target, correct, exchange);
        checkBig (node->right, target, correct, exchange);
    }
    void checkSmall (TreeNode* node, int& target, bool& correct, TreeNode** exchange) {
        if (!node) return;
        if (node->val < target) {
            correct = false;
            target = node->val;
            *exchange = node;
        }
        checkSmall (node->left, target, correct, exchange);
        checkSmall (node->right, target, correct, exchange);
    }
    void go (TreeNode* node, bool& found) {
        if (!node || found) return;
        bool right = true, left = true;
        int temp ,nt = node->val;
        TreeNode** target = new TreeNode*;
        checkSmall(node->right,nt,right,target);
        TreeNode** ltarget = new TreeNode*;
        checkBig(node->left,nt,left,ltarget);

        if (!right && !left) {
            found = true;
            temp = (*target)->val;
            (*target)->val = (*ltarget)->val;
            (*ltarget)->val = temp;
        } else if (!left) {
            //cout <<"chage " << target <<" with " << node->val << endl;
            found = true;
            temp = node->val;
            node->val = (*ltarget)->val;
            (*ltarget)->val = temp;
        } else if (!right) {
            //cout <<"chage " << (*target)->val <<" with " << node->val << endl;
            found = true;
            temp = node->val;
            node->val = (*target)->val;
            (*target)->val = temp;
        }
   
        go (node->left, found);
        go (node->right, found);
    }
    void recoverTree(TreeNode* root) {
        bool found = false;
        go (root,found);
    }
};
//the fatest method
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr,*second = nullptr,*parent = nullptr;
        TreeNode* cur,*pre;
        cur = root;
        while(cur){
            if(!cur->left){
                if(parent && parent->val > cur->val){
                    if(!first) first = parent;
                    second = cur;
                }
                parent = cur;
                cur = cur->right;
                
            }else{
                pre = cur->left;
                while(pre->right &&pre->right != cur) pre = pre->right;
                if(!pre->right){
                    pre->right = cur;
                    cur = cur->left;
                }else{
                    pre->right = nullptr;
                    if(parent->val > cur->val){
                        if(!first) first = parent;
                        second = cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
                
                
            }
        }
        swap(first->val,second->val);
    }
};
