/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>num;
        for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next) {
            num.emplace_back(ptr->val);
        }
        int count = -1, j, i = 0;
        for (ListNode* ptr = head; ptr != NULL; ptr=ptr->next,j--,i++) {
            if (i%k == 0) {
                j = i+k-1;
            }
            if (j < num.size()) {
                ptr->val = num[j];
            } else {
                break;
            }
        }
        return head;
    }
};
//the 12 ms solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) {
            
    ListNode* begin;
    if (head==NULL || head->next ==NULL || k==1)
    	return head;
        
    ListNode* dummyhead = new ListNode(-1);
    dummyhead->next = head;
    begin = dummyhead;
    int i=0;
        
    while (head){
    	i++;
    	if (i%k == 0){
    		begin = reverse(begin, head->next);
    		head = begin->next;
    	} else {
    		head = head->next;
    	}
    }
    return dummyhead->next;
    
}

ListNode* reverse(ListNode* begin, ListNode* end){
        ListNode* curr = begin->next;
        ListNode* next, *first;
        ListNode* prev = begin;
        first = curr;
        while (curr!=end){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        begin->next = prev;
        first->next = curr;
        return first;
    }

    
};
