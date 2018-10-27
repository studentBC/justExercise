/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void revert(struct TreeNode* node) {
    struct TreeNode* temp;
    if (node == NULL) {
        return;
    }
    temp = node->left;
    node->left = node->right;
    node->right = temp;
    revert(node->left);
    revert(node->right);
    return;
}
struct TreeNode* invertTree(struct TreeNode* root) {
    revert(root);
    return root;
}
