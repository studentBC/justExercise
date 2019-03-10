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
    void go (TreeNode* node, vector<int>&temp) {
        if (!node) return;
        temp.push_back(node->val);
        go (node->left, temp);
        go (node->right, temp);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        vector<int>temp;
        go(root,temp);
        sort(temp.begin(), temp.end());
        int prev = temp[0];
        for (int i = 0; i < temp.size(); i++) {
            if (prev!=temp[i]) {
                return temp[i];
            }
        }
        return -1;
    }
};
//use the least memory
class Solution {
public:
    int first = INT_MAX, second= INT_MAX;
    void preorder(TreeNode* root){
        
        if(!root) return ;
        if(root->val < first){
            first = root->val;
            
        }
        else if(root->val < second && first != root->val){
            second = root->val;
        }
        preorder(root->left);
        
        preorder(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        preorder(root);
        return second != INT_MAX? second:-1;
    }
};
