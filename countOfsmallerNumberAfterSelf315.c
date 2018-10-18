//fatest method
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct node {
    struct node *left;
    struct node *right;
    int small;
    int v;
};

struct node *
new_node(int v)
{
    struct node *n = malloc(sizeof(*n));
    if (n) {
        n->left = n->right = 0;
        n->small = 0;
        n->v = v;
    }
    return n;
}

int
insert(struct node **p, int v)
{
    int sum = 0;
    
    while (*p) {
        if (v >= (*p)->v) {
            sum += (*p)->small;
            if (v > (*p)->v) {
                sum++;
            }
            p = &(*p)->right;
        } else {
            (*p)->small++;
            p = &(*p)->left;
        }
    }
    *p = new_node(v);
    return sum;
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int *ret = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    struct node *r = 0;
    for (int i = numsSize -1 ; i >=0 ; i--) {
        ret[i] = insert(&r, nums[i]);
    }
    return ret;
}
//my method
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    int count = 0;
    int limit = numsSize -1;
    for (int i = 0; i < limit ; i++) {
        count = 0;
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] > nums[j]) {
                count++;
            }
        }
        ans[i] = count;
    }
    ans[limit] = 0;
    return ans;
}
