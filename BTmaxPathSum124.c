//the fatest method
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(_a,_b) (_a > _b ? _a : _b)
#define MAX4(_a,_b,_c,_d) (MAX(MAX(_a,_b),MAX(_c,_d)))

int maxPathSumRec(struct TreeNode *root, int *max)
{
    int l, r, localMax;
    
    if (!root) {
        return 0;
    }
    l = maxPathSumRec(root->left, max);
    r = maxPathSumRec(root->right, max);
    
    l = l > 0 ? l : 0;
    r = r > 0 ? r : 0;
    // here we find what is the max, either the current node, current node +
    // right child, current node + left child, or current node + all child
    //localMax = MAX4(root->val, root->val + l, root->val + r, root->val + l + r);
    localMax = root->val + l + r;
    if (localMax > *max) {
        *max = localMax;
    }
    return root->val + MAX(r,l);
}

int maxPathSum(struct TreeNode* root) {
    int max = INT_MIN;
    
    maxPathSumRec(root, &max);
    return max;
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
void gofind(struct TreeNode* node, int* sum, int* max) {
    if (!node) return;
    //int prev = *sum;
    *sum=*sum+node->val;
    if (*sum > *max)*max = *sum;
    //printf("max: %d  , val: %d, sum: %d\n",*max,node->val,*sum);
    gofind(node->left, sum, max);
    gofind(node->right, sum, max);
    *sum = *sum-node->val;
    //printf("val: %d, sum: %d\n",node->val,*sum);
}
void go (struct TreeNode* node, int* ans, int* sum, int* max) {
    if (!node)return;
    *max = INT_MIN;
    *sum = 0;
    int Max = node->val;
    gofind(node->left, sum, max);
    //printf("1. max:  %d\n",*max);
    if (*max>0)Max+=*max;
    *max = INT_MIN;
    *sum = 0;
    gofind(node->right, sum, max);
    if (*max>0)Max+=*max;
    //printf("2. max:  %d\n",*max);
    if (*ans < Max) *ans = Max;
    go(node->left, ans, sum, max);
    go(node->right, ans, sum, max);
}
int maxPathSum(struct TreeNode* root) {
    if (!root) return 0;
    int* ans = malloc(sizeof(int));
    int* max = malloc(sizeof(int));
    int* sum = malloc(sizeof(int));
    *ans = *max = INT_MIN;
    *sum = 0;
    go(root, ans, sum, max);
    return *ans;
}
