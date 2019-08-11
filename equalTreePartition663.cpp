/*
Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

Example 1:

Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation: 
    5
   / 
  10
      
Sum: 15

   10
  /  \
 2    3

Sum: 15
Example 2:

Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
Note:

The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000

wrong test case:
[0,-1,1]
*/
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
    void go (TreeNode* node, int& total) {
        if (!node) return;
        total+=node->val;
        go (node->left, total);
        go (node->right, total);
    }
    void travel (TreeNode* node, int half,bool& found) {
        if (!node || found) return;
        int temp = 0;
        go (node,temp);
        if (temp == half) {
            found = true;return;
        }
        travel (node->left, half, found);
        travel (node->right, half, found);
    }
    bool checkEqualTree(TreeNode* root) {
        int total = 0;
        go (root,total);
        if (total%2) return false;
        bool found = false;
        travel(root->left,total/2, found);
        travel(root->right,total/2, found);
        return found;
    }
};
//the fatest method
class Solution {
public:
    int TreeSum(TreeNode *root){
        if(!root) return 0; 
        root->val += TreeSum(root->left) + TreeSum(root->right); 
        return  root->val; 
    }
    
    bool checkEqual(TreeNode* root, int total){
        if(!root) return false; 
        if(root->left && root->left->val == total - root->left->val) return true; 
        if(root->right && root->right->val == total - root->right->val) return true; 
        
        return checkEqual(root->left, total) || checkEqual(root->right, total); 
    }
    
    bool checkEqualTree(TreeNode* root) {
        if(!root) return true; 
        TreeSum(root); 
        return checkEqual(root, root->val); 
        
    }
};
