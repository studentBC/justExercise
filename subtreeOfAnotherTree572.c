/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void judge(struct TreeNode* s, struct TreeNode* t, bool* same) {
    if (!s || !t) {
        if (!s && !t) {
            return;
        } else {
            *same = false;
            return;
        }
    }
    if (s->val != t->val) {
        *same = false;
    }
    judge(s->left, t->left, same);
    judge(s->right, t->right, same);
    return;
}
void go (struct TreeNode* s, struct TreeNode* t, bool* ans, bool* same) {
    if (!s || *ans)return;
    if (s->val == t->val) {
        printf("%d \n",s->val);
        *same = true;
        judge(s, t, same);
        *ans = *same;
    }
    go (s->left, t , ans, same);
    go (s->right, t, ans, same);
    return;
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if (!s || !t) {
        if (!s && !t) {
            return true;
        } else {
            return false;
        } 
    }

    bool* ans = malloc(sizeof(bool));
    bool* same = malloc(sizeof(bool));
    *ans = false;
    go (s, t, ans, same);
    return *ans;
}
