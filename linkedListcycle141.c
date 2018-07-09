/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
       struct ListNode * one = head,* two = head;
		while(one && two && two->next){
			one = one->next;
			two=two->next->next;
			if(one == two){
				return true;
			}
		}
    return false;
}
