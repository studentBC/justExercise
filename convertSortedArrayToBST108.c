/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* newNode(int data)
{
    struct TreeNode * node = malloc(sizeof(TreeNode));
    node->val = data;
    node->left = node->right = NULL;
    return (node);
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    int half = numsSize/2;
    Struct TreeNode * root = newNode(nums[half]);
    int i = 0;
    for (i = 0; i < half;i++) {
        
    }
    
}
