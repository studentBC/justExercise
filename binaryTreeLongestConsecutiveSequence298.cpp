/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

Example 1:

Input:

   1
    \
     3
    / \
   2   4
        \
         5

Output: 3

Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
Example 2:

Input:

   2
    \
     3
    / 
   2    
  / 
 1

Output: 2 

Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.

wrong test case:
[]
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
    void go (TreeNode* node, int parent, int len, int& ans) {
        if (!node) return;
        if (parent+1 == node->val) {
            len++;
            ans = max(ans, len);
        } else {
            len = 0;
        }
        go (node->left, node->val, len, ans);
        go (node->right, node->val, len, ans);
        return;
    }
    int longestConsecutive(TreeNode* root) {
        if(!root)return 0;
        int ans = 0, len = 0;
        go (root, INT_MIN, len, ans);
        return ans+1;
    }
};
//the fatest method
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
		int res = 0;
		dfs(root, root->val, 0, res);
		return res;
	}
	void dfs(TreeNode* root, int v, int out, int& res) {
		if (!root) return;
		if (root->val == v + 1) ++out;
		else out = 1;
		res = max(res, out);
		dfs(root->left, root->val, out, res);
		dfs(root->right, root->val, out, res);	
    }
};
