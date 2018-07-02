/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max = -1;
void printPostorder(struct TreeNode* node,int* count)
{
     if (node == NULL){
         //*count = *count-1;
         return;
     }
    
    
    
    *count = *count+1;
     // first recur on left subtree
     printPostorder(node->left,count);
     // then recur on right subtree
     printPostorder(node->right,count);
    
     // now deal with the node
    
     printf("%d ", node->val);
     printf("%d\n",*count);
    if(*count > max){
        max = *count;
    }
     *count = *count-1;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int* count = malloc(sizeof(int));
    *count = 0;
    max = -1;
    printPostorder(root,count);
    
    return max;
    
}
//the fatest method
//is as below
int maxDepth(struct TreeNode* root) {
    int left, right;
    
    if(root != NULL) {
        left = maxDepth(root->left);
        right = maxDepth(root->right);
        
        if(left > right)
            return 1 + left;
        
        return 1 + right;
    }
    
    return 0;
}
