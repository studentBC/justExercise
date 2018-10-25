/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void merge(struct TreeNode* t1, struct TreeNode* t2, bool* child) {
    if (t1 == NULL || t2 == NULL) {
        if (t2) {
            *child = true;
        } 
        return;
    }  
    t1->val = t1->val + t2->val;
    merge(t1->left,t2->left,child);
    if (*child) {
        t1->left = t2->left;
        t2->left = NULL;
        *child = false;
    }
    merge(t1->right, t2->right,child);
    if (*child) {
        t1->right = t2->right;
        t2->right = NULL;
        *child = false;
    }
    return;
}  
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    bool* child = malloc(sizeof(bool));
    *child = false;
    if (t1 == NULL && t2 != NULL) {
        return t2;
    } else if (t1!=NULL && t2 == NULL) {
        return t1;
    }
    merge(t1, t2, child);
    return t1;
}
//fatest method
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#if 0
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    // base case
    if (t1 == NULL && t2 == NULL) return NULL;
    else if (t1 == NULL) return t2;
    else if (t2 == NULL) return t1;
    
    struct TreeNode* result = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    result->val = t1->val + t2->val;
    result->left = mergeTrees(t1->left, t2->left);
    result->right = mergeTrees(t1->right, t2->right);
    
    return result;
}
#endif

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if(t1==NULL&&t2==NULL)
        return NULL;
    if(t1!=NULL&&t2!=NULL){
        t1->left=mergeTrees(t1->left,t2->left);
        t1->right=mergeTrees(t1->right,t2->right);
        t1->val+=t2->val;
        return t1;
    }else if(t2!=NULL){
        return t2;
    }
        
    return t1;
    
}
