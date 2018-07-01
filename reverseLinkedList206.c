/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    int count = 0,i = 0;
    struct ListNode *location = head;
    while(location != NULL) {
        location = location->next;
        count++;
    }
    //printf("%d \n",count);
    int list[count];
    location = head;
    while(location != NULL) {
        list[i] = location->val;
        location = location->next;
        i++;
    }
    location = head;
    i = count-1;
    while(location != NULL) {
        location->val = list[i];
        location = location->next;
        i--;
    }
    return head;
}
