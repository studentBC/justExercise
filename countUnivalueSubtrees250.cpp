/*
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

Example :

Input:  root = [5,1,5,5,5,null,5]

              5
             / \
            1   5
           / \   \
          5   5   5

Output: 4
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
void check (TreeNode* node, bool& legal, int& value) {
	if (!node || !legal) return;
	if (node->val != value) {
		legal = false;
		return;
	}
	check(node->left, legal, value);
	check(node->right, legal, value);
}
void go (TreeNode* node, int& ans) {
	if (!node) return;
	bool legal = true;
	check(node, legal, node->val);
	if (legal) ans++;
	go (node->left, ans);
	go (node->right, ans);
}
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
		int ans = 0;
		go (root,ans);
		return ans;
    }
};
//the fatest method
class Solution {
public:
    
    bool recurse(TreeNode* root, int& count)
    {
        if(root == NULL)
            return true;
        
        
        
        bool left = recurse(root->left,count);
        bool right = recurse(root->right,count);
        
        if(left == true && right == true) 
        {
            if(root->left != NULL && root->val == root->left->val && (root->right != NULL && root->val == root->right->val))
            {
                count++;
                return true;
            }
            else if(root->left == NULL && (root->right != NULL && root->val == root->right->val))
            {
                count++;
                return true;
            }
            else if(root->right == NULL && (root->left != NULL && root->val == root->left->val))
            {   
                count++;
                return true;
            }
            else if(root->left == NULL && root->right == NULL)
            {
                count++;
                return true;
            }
        }
        return false;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int count = 0;
        recurse(root,count);
        return count;
        
    }
};
