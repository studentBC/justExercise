/*
 * Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example :

Input: [1,2,3]
Output: [1,2,4]


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
    ListNode* plusOne(ListNode* head) {
		vector<int>num;
		ListNode* ptr;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			num.emplace_back(ptr->val);
		}
		bool forward = true;
		for (int i = num.size()-1; i > -1; i--) {
			if (forward) num[i]++;
			if (num[i]>=10) {
				forward = true;
				num[i]-=10;
			} else {
				forward = false;
				break;
			}
		}
		ptr = head;
		for (int i = 0; i < num.size(); i++) {
			ptr->val = num[i];
			ptr = ptr->next;
		}
		ptr = NULL;
		if (forward) {
			ptr = new ListNode(1);
			ptr->next = head;
			return ptr;
		}
		return head;
    }
};
//the fatest method
class Solution {
public:
    int addOne(ListNode *p)
    {
        int sum = p->val + (p->next ? addOne(p->next) : 1);
        p->val = sum % 10;
        return   sum / 10;
    }
    
    ListNode* plusOne(ListNode* head)
    {
        if(!addOne(head)){
            return head;
        }
        
        auto p = new ListNode(1);
        p->next = head;
        return p;
    }
};
