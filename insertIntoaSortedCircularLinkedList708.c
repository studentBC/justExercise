/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct TreeNode *next;
 * };
 */

struct Node* insert(struct Node* head, int insertVal) {
    if (!head) {
        head = (struct Node*)malloc(sizeof(struct Node));
        head->val = insertVal;
        head->next = head;
        return head;
    }
    struct Node* ans= (struct Node*)malloc(sizeof(struct Node));
    ans->val = insertVal;
    struct Node* biggest = head;
    int big = head->val, c = 0;
    for (struct Node* ptr = head,*prev = NULL; c < 2; ptr = ptr->next) {
        if (ptr == head) c++;
        if (insertVal >= ptr->val && ptr->next->val >= insertVal) {
            ans->next = ptr->next;
            ptr->next = ans;
            return head;
        } 
        if (ptr->val >= big) {
            biggest = ptr;
            big = ptr->val;
        }
    }
    ans->next = biggest->next;
    biggest->next = ans;
    return head;
}
