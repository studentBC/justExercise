/*
 * Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

    Given target value is a floating point.
    You are guaranteed to have only one unique value in the BST that is closest to the target.

Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

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
class Solution {
public:
	void go (TreeNode* node, double target, double& d, int& ans) {
		if (!node) return;
		double temp = abs(target-node->val);
		if (temp < d) {
			d = temp; ans = node->val;
		}
		go (node->left, target, d, ans);
		go (node->right, target, d, ans);
	}
    int closestValue(TreeNode* root, double target) {
		int ans;
		double d = DBL_MAX;
		go (root, target, d, ans);
		return ans;
    }
};
//the fatest method
class Solution {
public:
    
    void helper(TreeNode* root, double t, tuple<double, int> &res)
    {
        if(not root)
        {
            return;
        }

       
        double currdiff = abs(root->val - t);
        if(currdiff < std::get<0>(res))
        {
            res = {currdiff, root->val};
        }
        
        if(root->val < t)
        {
            helper(root->right , t , res);
        }
        else if(root->val > t)
        {
            helper(root->left , t , res);
        }
    }
    
    int closestValue(TreeNode* root, double target) {
        
        std::tuple<double, int> res = {LONG_MAX, 0};
        helper(root, target , res);
        return std::get<1>(res);
    }
};
