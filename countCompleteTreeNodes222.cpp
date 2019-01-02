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
	void go (TreeNode* node, int& count) {
		if (!node) return;
		count++;
		go (node->left,count);
		go (node->right,count);
		return;
	}
    int countNodes(TreeNode* root) {
		
		int count = 0;
		go (root,count);
		return count;
    }
};
//the fatest method
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

    int countNodes(TreeNode* root) {
        if(root==NULL || root->val==INT_MIN) return 0;
        root->val =INT_MIN;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
