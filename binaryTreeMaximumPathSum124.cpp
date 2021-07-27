/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int ans = INT_MIN;
    int go (TreeNode* node) {
        if (!node) return 0;
        int left = max(go (node->left), 0);
        int right = max(go (node->right), 0);
		ans = max(ans, left+right+node->val);
		return node->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
       	go (root);
		return ans;
    }
};
//https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603423/Python-Recursion-stack-thinking-process-diagram
