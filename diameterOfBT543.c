//fatest method
int height(struct TreeNode* root, int *ans) {
    if(!root) return 0;
    
    int lheight = height(root -> left, ans);
    int rheight =  height(root -> right, ans);
    
    int currentDia =  lheight + rheight;
    
    *ans = *ans > currentDia ? *ans : currentDia;
    
    return lheight > rheight ? (lheight + 1) : (rheight + 1); 
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int dm;
    height(root, &dm);
    return dm;
}
// my method
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void find (struct TreeNode* node , int* count, int* max) {
    if (node == NULL) {
        if (*count > *max) {
            *max = *count;
        }   
        return ;
    }  
    *count = *count +1;
    //printf("%d: %d\n",node->val, *count);
    find(node->left , count, max);

    find(node->right , count, max);
    *count = *count -1;
    return ;
}  
int go(struct TreeNode* root) {
    int* left = malloc(sizeof(int));
    int* right = malloc(sizeof(int));
    int* count = malloc(sizeof(int));
    *left = *right = *count = 0;
    find(root->left , count, left);
    *count = 0;
    find(root->right, count, right);
    return *left + *right;
}
void findout (struct TreeNode* node,int* max) {
    if (node == NULL) {
        return;
    }
    int count = go(node);
    if (*max < count) {
        *max = count;
    }
    findout(node->left, max);
    findout(node->right, max);
    return;
}
int diameterOfBinaryTree(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } 
    int* max = malloc(sizeof(int));
    *max = 0;
    findout(root,max);
    return *max;
}

