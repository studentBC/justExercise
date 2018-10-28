/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void go(struct TreeNode* node , int* min, int* count) {
    
    if (node == NULL) {
        return ;
    }
    
    *count = *count+1;
    //printf("val: %d , count: %d \n",node->val,*count);
    if (node->left == NULL && node->right == NULL) {
        if (*count < *min) {
            *min = *count;
            //printf("val: %d , min: %d \n",node->val,*min);
        }
    }
    go(node->left,min,count);
    //*count = *count-1;
    go(node->right,min,count);
    *count = *count-1;
    return;
}
int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int* min = malloc(sizeof(int));
    int* count = malloc(sizeof(int));
    *min = INT_MAX;
    *count = 0;
    go(root,min,count);
    return *min;
}
