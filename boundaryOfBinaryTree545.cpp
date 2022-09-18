/*
One simple approach is to divide this problem into three subproblems- left boundary, leaves and right boundary.

Left Boundary: We keep on traversing the tree towards the left and keep on adding the nodes in the resres array, provided the current node isn't a leaf node. If at any point, we can't find the left child of a node, but its right child exists, we put the right child in the resres and continue the process. The following animation depicts the process.

Leaf Nodes: We make use of a recursive function addLeaves(res,root), in which we change the root node for every recursive call. If the current root node happens to be a leaf node, it is added to the resres array. Otherwise, we make the recursive call using the left child of the current node as the new root. After this, we make the recursive call using the right child of the current node as the new root. The following animation depicts the process.

Right Boundary: We perform the same process as the left boundary. But, this time, we traverse towards the right. If the right child doesn't exist, we move towards the left child. Also, instead of putting the traversed nodes in the resres array, we push them over a stack during the traversal. After the complete traversal is done, we pop the element from over the stack and append them to the resres array. The following animation depicts the process.
*/ 

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
    void go (TreeNode* node, vector<int>& tmp) {
        if (!node->left && !node->right) tmp.push_back(node->val);
        else {
            if (node->left) go (node->left, tmp);
            if (node->right) go (node->right, tmp);
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int>ans;
        if (!root) return ans;
        if (root->left || root->right) ans.push_back(root->val);
        TreeNode* n = root->left;
        while (n) {
            if (n->left || n->right) ans.push_back(n->val);
            if (n->left) n = n->left;
            else n = n->right;
        }
        go (root, ans);
        vector<int>stack;
        n = root->right;
        while (n) {
            if (n->left || n->right) stack.push_back(n->val);
            if (n->right) n = n->right;
            else n = n->left;
        }
        while (!stack.empty()) {
            ans.push_back(stack.back());
            stack.pop_back();
        }
        return ans;
    }
};
