/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void go(struct TreeNode* node, int* sum, int target,int* anwser) {
	if (!node) return ;
	*sum= *sum + node->val;
	if (*sum == target) {
		*anwser = *anwser +1;
	}
	go(node->left, sum, target);
	go(node->right, sum, target);
	*sum = *sum - node->val;
	return;
}

void preorder(struct TreeNode* node, int* ans, int* s, int target,int* anwser) {
	if (!node) 	return;

	*s =  *anwser =  0;
	go(node,s,target,anwser);
	*ans = *ans + *anwser;

	preorder(node->left,ans,s,target,anwser);
	preorder(node->right,ans,s,target,anwser);
	return;
}
int pathSum(struct TreeNode* root, int sum) {
	int* ans = malloc(sizeof(int));
	int* anwser = malloc(sizeof(int));
	int* s = malloc(sizeof(int));
	*ans = 0;
	preorder(root,ans,s,sum,anwser);
	return *ans;
}
//the fatest method
void
pathSum_int (struct TreeNode* root, int sum, int *count, 
                                        int *stack, int level) {
    int i, tmp=0;
    if (!root)
        return;
    stack[level] = root->val;
    
    for (i=level; i >= 0; --i) {
        tmp +=stack[i];
        
        if (tmp == sum) {
            ++(*count);
        }
    }
    pathSum_int (root->left, sum, count, stack, (level +1));
    pathSum_int (root->right, sum, count, stack, (level +1));    
}
int pathSum(struct TreeNode* root, int sum) {
    int count=0;
    int stack[1000];
    pathSum_int(root, sum, &count, stack, 0);
    return count;
    
}
