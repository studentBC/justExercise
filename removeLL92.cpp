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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* ptr;int count = 1 , i = 0;
        int* temp = new int[n-m+1];
        for (ptr = head; ptr!=NULL; ptr = ptr->next) {
            if (count>=m && count <= n) {
                temp[i] = ptr->val;
                i++;
            } else if (count > n) break;
            count++;
        }
        count = 1;i--;
        for (ptr = head; ptr!=NULL; ptr = ptr->next) {
            if (count>=m && count <= n) {
                ptr->val = temp[i];
                i--;
            } else if (count > n) break;
            count++;
        }
        return head;
    }
};

