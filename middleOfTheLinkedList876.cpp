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
    ListNode* middleNode(ListNode* head) {
		ListNode* ptr = NULL;
		vector<ListNode*>temp
 		for (ptr = head; ptr!=NULL; ptr = ptr->next) {
			temp.push_back(ptr);
		}
		return temp[temp.size()/2];
    }
};
