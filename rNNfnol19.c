/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int count = 0 , i;
    struct ListNode* ptr = head;
    while(ptr) {
        ptr = ptr->next;
        count++;
    }
    if (n!=count) {
        count-=n;
        ptr = head;
        for (i = 0; i < count-1;i++) {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
    } else {
        head = head->next;
    }
    return head;
}
