/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool ismirror(struct TreeNode* t1 , struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) {
        return true;
    }
    if ( t1 && t2 && t1->val == t2->val ) {
        printf("%d\n",t1->val);
        return ismirror(t1->left,t2->right) && ismirror(t1->right,t2->left);
    }
    return false;
}

bool isSymmetric(struct TreeNode* root) {
    return ismirror(root,root);
}
