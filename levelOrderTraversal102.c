/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/* frunction prototypes */
struct TreeNode** createQueue(int *, int *);
void enQueue(struct TreeNode **, int *, struct TreeNode *);
struct TreeNode *deQueue(struct TreeNode **, int *);

/*UTILITY FUNCTIONS*/
struct TreeNode** createQueue(int *front, int *rear)
{
    struct TreeNode **queue =
        (struct TreeNode **)malloc(sizeof(struct TreeNode*)*500);
 
    *front = *rear = 0;
    return queue;
}
 
void enQueue(struct TreeNode **queue, int *rear, struct TreeNode *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}
 
struct TreeNode *deQueue(struct TreeNode **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

void LevelTraversal(struct TreeNode* root , int* draft)
{
    int rear, front;
    struct TreeNode **queue = createQueue(&front, &rear);
    struct TreeNode *temp_node = root;
    int i = 0;
    while (temp_node)
    {
        printf("%d ", temp_node->val);
        draft[i] = temp_node->val;
        i++;
        /*Enqueue left child */
        if (temp_node->left) {
            enQueue(queue, &rear, temp_node->left);
        } else {
            draft[i] = -1;
            i++;
        }
            
 
        /*Enqueue right child */
        if (temp_node->right) {
            enQueue(queue, &rear, temp_node->right);
        } else {
            draft[i] = -1;
            i++;
        }
            
        
        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front);
    }
}


int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int** ans = malloc(sizeof(int*)*100)
    double p2 = 1;
    int* draft = malloc(sizeof(int)*500);
    LevelTraversal(root,draft);
    for (int i = 1; i < 101 ;i++) {
        ans[i-1] = malloc(sizeof(int)*p2);
        p2*=2;
    }
    
}
