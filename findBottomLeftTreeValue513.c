/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void go(struct TreeNode* node, int x, int y, int* tx, int* ty, int* ans) {
    if (!node)return;
    go (node->left,x-1,y+1,tx,ty,ans);
    if (y > *ty) {
        *ty = y;
        *tx = x;
        *ans = node->val;
    } else if ( y == *ty && x < *tx) {
        *tx = x;
        *ans = node->val;
    } 
    go (node->right,x+1,y+1,tx,ty,ans);
    
    return;
}
int findBottomLeftValue(struct TreeNode* root) {
    int* tx = malloc(sizeof(int));
    int* ty = malloc(sizeof(int));
    *ty = -1;*tx = 0;
    int x = 0 ,y = 0;
    int* ans = malloc(sizeof(int));
    go(root,x,y,tx,ty,ans);
    return *ans;
}
