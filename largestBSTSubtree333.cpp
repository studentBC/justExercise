/*
 * Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.

Example:

Input: [10,5,15,1,8,null,7]

   10
   / \
  5  15
 / \   \
1   8   7

Output: 3
Explanation: The Largest BST Subtree in this case is the highlighted one.
             The return value is the subtree's size, which is 3.

Follow up:
Can you figure out ways to solve it with O(n) time complexity?

 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * wrong test case:
 * [3,2,4,null,null,1]
 *
 * we should check and learn at this website
 * https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
 * 
 * the wrong test case we violate 
 * is not check if max value in left subtree is smaller than the node and min value in right subtree greater than the node.
 *
 * after that we use a better solution looks at each node only once. The trick is to write a utility helper function isBSTUtil(struct node* node, int min, int max) that traverses down the tree keeping track of the narrowing min and max allowed values as it goes, looking at each node only once. The initial values for min and max should be INT_MIN and INT_MAX — they narrow from there.
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
	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 * };
	 */
	int check (TreeNode* node, int min, int max, int& nums) {
		/* an empty tree is BST */
		if (node==NULL)
			return 1;
		nums++;
		/* false if this node violates
		the min/max constraint */
		if (node->val < min || node->val > max)
			return 0;
	   
		/* otherwise check the subtrees recursively,
		tightening the min or max constraint */
		return
			check(node->left, min, node->val-1, nums) && // Allow only distinct values
			check(node->right, node->val+1, max, nums); // Allow only distinct values

	}
	void go (TreeNode* node, int& ans) {
		if (!node) return;
		int nums = 0;
		if (check(node, INT_MIN, INT_MAX, nums)) ans = max(nums, ans);
		go (node->left, ans);
		go (node->right, ans);
	}
	int largestBSTSubtree(TreeNode* root) {
		int ans = 0;
		go (root, ans);
		return ans;
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

// Watched Tushar's video: https://www.youtube.com/watch?v=4fiDs7CCxkc

struct TreeInfo
{
    TreeInfo() = default;
    
    bool isBst = true;
    int size = 0;
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root)
    {
        const auto result = largestBst(root);
        return result.size;
    }
    
private:
    TreeInfo largestBst(TreeNode* root)
    {
        if (!root)
        {
            return TreeInfo{ };
        }
        
        auto lhs = largestBst(root->left);
        auto rhs = largestBst(root->right);
        
        TreeInfo result;
        
        if (!lhs.isBst || !rhs.isBst || (lhs.max >= root->val || rhs.min <= root->val))
        {
            result.isBst = false;
            result.size = std::max(lhs.size, rhs.size);
            // Min and max values don't matter in this case...
            
            return result;
        }
        
        result.isBst = true;
        result.size = lhs.size + rhs.size + 1;
        result.min = root->left ? lhs.min : root->val;
        result.max = root->right ? rhs.max : root->val;
        
        return result;
    }
    
};
