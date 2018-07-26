/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
	 int count = 0, i = 0;
    if (head == NULL){
        return true;
    }
    struct ListNode* tail = head;
    while (tail) {
        tail = tail->next;
        count++;
    }
    int temp[count];
    count = 0;
    tail = head;
    while (tail) {
        temp[count] = tail->val;
        tail = tail->next;
        count++;
    }
    int total = count;
    if (count%2 == 0) {
        count/=2;
        for (i = 0; i < count;i++) {
            if (temp[i] != temp[total-1-i]) {
                return false;
            }
        }
    } else {
        count/=2;count++;
        for (i =0; i < count; i++) {
            if (temp[i] != temp[total-1-i]) {
                return false;
            }
        }
    }
    return true;
}
