/*
Given the root of a binary tree, find the maximum average value of any subtree of that tree.

(A subtree of a tree is any node of that tree plus all its descendants. The average value of a tree is the sum of its values, divided by the number of nodes.)

 

Example 1:



Input: [5,6,1]
Output: 6.00000
Explanation: 
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.
 

Note:

The number of nodes in the tree is between 1 and 5000.
Each node will have a value between 0 and 100000.
Answers will be accepted as correct if they are within 10^-5 of the correct answer.
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
	void get (TreeNode* node, double& sum, double& count) {
		if(!node) return;
		sum+=node->val;
		count++;
		get (node->left, sum, count);
		get (node->right, sum, count);
	}
	void go (TreeNode* root, double& ans) {
		if(!node) return;
		go (node->left, ans);
		go (node->right, ans);
		double sum = 0, count = 0;
		get(node,sum, count);
		ans = max (ans, sum/count);
	}
    double maximumAverageSubtree(TreeNode* root) {
 		double ans = 0;
		go (root, ans);
		return ans;
    }
};
//the fatest method
class Solution {
    int N = 0;
    double res = INT_MIN;
public:
    double ave(TreeNode* root) {
        if(root == NULL) return 0;
        int curN = N;
        double left = ave(root->left);
        int leftN = N;
        double right = ave(root->right);
        double curv = (left * (leftN - curN) + right *(N - leftN) + root->val)/(N - curN + 1);
        if(curv > res) res = curv;
        N++;
        return curv;
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        res = INT_MIN;
        ave(root);
        return res;
    }
};
