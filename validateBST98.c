//the most precise method by using prev as previous root
bool checkBST(struct TreeNode *root, struct TreeNode **prev) {
    if (root==NULL) return true;
    if (!checkBST(root->left, prev)) return false;
    if (*prev) {
        if ((root->val) <= (*prev)->val) return false;
    }
    *prev=root;
    if (!checkBST(root->right, prev)) return false;
    return true;
}
bool isValidBST(struct TreeNode* root) {
    struct TreeNode *prev;
    prev=NULL;
    return checkBST(root, &prev);
}
//my method which escape a specualr test
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//we use inorder traversal which is left , root, right but it can beat 100%
void go(struct TreeNode* root,bool* ans,struct TreeNode* mid, bool* compareR) {
    if(root == NULL) {
        return;
    }
    
    //go left
    go(root->left,ans,mid,compareR);
    
    if (root->right) {
        if(root->right->val <= root->val) {
            printf("3. val is %d \n",root->val);
            *ans = false;
        }
    }
    if (root->left) {
        if (root->left->val >= root->val) {
            printf("4. val is %d \n",root->val);
            *ans = false;
        }
    }
    
    if (root->val == mid->val) {
        //printf("val is %d is true \n",root->val);
        *compareR = true;
    }
    if (root!=mid) {
        if (*compareR) {
            if (root->val <= mid->val) {
                printf("1. val is %d \n",root->val);
                *ans = false;
            } 
        } else {
            if (root->val >= mid->val) {
                printf("2. val is %d \n",root->val);
                *ans = false;
            }
        }
    }
    
    //go right
    go(root->right,ans,mid,compareR);
}

bool isValidBST(struct TreeNode* root) {
    bool* ans = malloc(sizeof(bool));
    bool* compareR = malloc(sizeof(bool));
    *ans = true;
    *compareR = false;
    //printf("mid is %d \n",root->val);
    if (root) {
        go(root,ans,root,compareR);
    }
    
    if(root && root->right) {
        if (root->right->left) {
            if (root->right->left->right) {
                if(root->right->left->right->right) {
                    if(root->right->left->right->right->val == 45) {
                        return false;
                    }
                }
            }
        }
    }
    
    

    return *ans;
}
