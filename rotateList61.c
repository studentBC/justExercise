/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL) {
        return NULL;
    }
    int count = 0;
    struct ListNode* ptr = head;
    struct ListNode* tail;
    while(ptr) {
        tail = ptr;
        ptr = ptr->next;
        
        count++;
    }
    //printf("%d \n",tail->val);
    int move;
    if (k>count) {
        if (k%count == 0) {
            return head;
        }
        move = count - k%count;
    } else {
        move = count -k;
    }
    ptr = head;
    //printf("count:%d , k: %d , move: %d \n",count,k,move);
    if (move == 0 || count <= 1 || k == 0) {
        return head;
    } else {
        struct ListNode* newhead;
        move--;
        for (int i = 0; i < move; i++) {
            ptr = ptr->next;
        }
        //printf("%d ,",ptr->val);
        newhead = ptr->next;
        ptr->next = NULL;
        tail->next = head;
        return newhead;
    }
    
}
