//fatest method
int kthSmallest_int(struct TreeNode* root, bool *flag, int k, int *count) {
    int val;
    if (!root)
        return 0;
    val = kthSmallest_int (root->left, flag, k, count);
    if (*flag == true) {
        return val;
    }
    ++(*count);
    if (*count == k) {
        *flag = true;
        return root->val;
    }
    return kthSmallest_int (root->right, flag, k, count);
}
    
int kthSmallest(struct TreeNode* root, int k) {
    if (!root || !k)
        return 0;
    bool flag = false; 
    int count=0;
    return kthSmallest_int (root, &flag, k, &count);   
}
//my method
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//left root right
void inorder(struct TreeNode* node , int* draft, int* count) {
    if (node == NULL) {
        return;
    }
    inorder(node->left, draft, count);
    //printf("%d , ",node->val);
    draft[*count] = node->val;
    *count = *count+1;
    inorder(node->right,draft, count);
}
int kthSmallest(struct TreeNode* root, int k) {
    int* draft = malloc(sizeof(int)*10000);
    int* count = malloc(sizeof(int));
    *count = 0;
    inorder(root, draft, count);
    return draft[k-1];
}
