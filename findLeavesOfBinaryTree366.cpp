
/**
 * Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.



Example:

Input: [1,2,3,4,5]

          1
         / \
        2   3
       / \
      4   5

Output: [[4,5,3],[2],[1]]



Explanation:

1. Removing the leaves [4,5,3] would result in this tree:

          1
         /
        2



2. Now removing the leaf [2] would result in this tree:

          1



3. Now removing the leaf [1] would result in the empty tree:

          []

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
    void go (TreeNode* node, vector<int>& temp) {
        if (!node) return;
        go (node->left, temp);
        go (node->right, temp);
		if (!node->left && !node->right) {
            temp.emplace_back(node->val);
            node = nullptr;
            return;
        }
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>>ans;
        while (root) {
            vector<int>temp;
            go (root,temp);
            ans.emplace_back(temp);
        }
        return ans;
    }
};
//the fatest method
class Solution {
private:
    int findLeavesHelper(TreeNode* root, vector<vector<int>>& result) {
        if (root) {
            int level = max(findLeavesHelper(root->left, result), findLeavesHelper(root->right, result));
            if (result.size() < level + 1) {
                result.resize(level + 1);
            }
            result[level].emplace_back(root->val);
            return level + 1;
        }
        return 0;
    }
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        findLeavesHelper(root, result);
        
        return result;
    }
};
