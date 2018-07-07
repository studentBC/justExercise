/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode * newNode(int data) {
     struct TreeNode * node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
     node->val = data;
     node->left = node->right = NULL;
     return (node);
 }
 void preOrder(struct TreeNode* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->val);
    preOrder(node->left);
    preOrder(node->right);
}
struct TNode* sortedToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct TreeNode *root = newNode(arr[mid]);
 
    /* Recursively construct the left subtree and make it
       left child of root */
    root->left =  sortedToBST(arr, start, mid-1);
 
    /* Recursively construct the right subtree and make it
       right child of root */
    root->right = sortedToBST(arr, mid+1, end);
 
    return root;
}
 struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
     struct TreeNode *root = sortedToBST(nums, 0, numsSize-1);
     //int * ans = (int *)malloc(sizeof(int)*numsSize);
   // preOrder(root,ans);
     return root;
 }
