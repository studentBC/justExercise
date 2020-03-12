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
	void go (TreeNode*& node, int target, TreeNode**& ans, bool& found) {
		if (!node || found) return;
		if (node->val == target) {
			ans = &node;
			found = true;
		}
		go (node->left, target, ans, found);
		go (node->right, target, ans, found);
	}
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		TreeNode** ans;
		bool found = false;
 		go (cloned, target->val, ans, found);       
		return *ans;
    }
};
//500 ms solution
class Solution {
public:
    TreeNode* dfs(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == NULL) {
            return NULL;
        }
        if (cloned == NULL) {
            return NULL;
        }
        if (original == target) {
            return cloned;
        }
        TreeNode* r = NULL;
        
        r = dfs(original->left, cloned->left, target);
        if (r != NULL) return r;
        r = dfs(original->right, cloned->right, target);
        if (r != NULL) return r;
        return NULL;
    }
    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* r = NULL;
        try {
            r = dfs(original, cloned, target);
        } catch( ...  ) {
            
        }
        return r;
    
    }
};
