/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    int count = 0;
    struct ListNode* ptr = head;

    while(ptr) {
        count++;
        ptr = ptr->next;
    }
    //printf("count is %d \n",count);
    if (count == 1) {
        return head;
    }
    int even = count/2;
    int odd = count - even;
    int ev[even] ; int od[odd];
    ptr = head;
    for (int i = 0; i < odd; i++) {
        od[i] = ptr->val;
        //printf("%d ,",od[i]);
        if (i != odd-1) {
            ptr = ptr->next->next;
        }
    }
    ptr = head->next;
    for (int i = 0; i < even; i++) {
        ev[i] = ptr->val;
        if (i != even-1) {
            ptr = ptr->next->next;
        }
    }
    ptr = head;
    for (int i = 0; i < odd; i++) {
        ptr->val = od[i];
        ptr = ptr->next;
    }
    for (int i = 0; i < even; i++) {
        ptr->val = ev[i];
        ptr = ptr->next;
    }
    return head;
}
