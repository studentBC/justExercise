/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void postT(struct TreeNode* node, int target,bool* ans,int* sum) {
    *sum=*sum + node->val;
    
    if (*sum == target && node->right == NULL && node->left == NULL) {
        *ans = true;
    }
    //printf("node: %d   ",node->val);
   // printf("sum: %d\n",*sum);
    if (node->left) {
        postT(node->left,target,ans,sum);
    } else if (node->right == NULL) {
        *sum=*sum - node->val;
        return;
    }
    if (node->right) {
        postT(node->right,target,ans,sum);
    } else {
        *sum= *sum - node->val;
        return;
    }
    *sum= *sum - node->val;
    
    return;
}
bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL) {
        return false;
    }
    int* s = malloc(sizeof(int));
    *s = 0;
    bool* ans = malloc(sizeof(bool));
    *ans = false;
    postT(root,sum,ans,s);
    return *ans;
}
