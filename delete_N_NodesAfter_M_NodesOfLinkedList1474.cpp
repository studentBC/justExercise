/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* ptr = head, *prev = head, *now;
        int i = 0, total = m+n;
        while (ptr != NULL) {
            i++;
            if (i == m) {
                prev = ptr;
            }
            if (i <= m) now = ptr;
            if (i == total) {
                i = 0;
                prev->next = ptr->next;
            }
            ptr = ptr->next;
        }
        now->next = NULL;
        return head;
    }

};
// 28 ms solution
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *curr = head;
        while (curr) {
            int i = 0;
            while (curr && ++i < m) {
                curr = curr->next;
            }
            if (curr == nullptr) {
                break;
            }
            int j = 0;
            ListNode *next = curr;
            while (next && j++ < n) {
                next = next->next;
            }
            if (next) {
                curr->next = next->next;
            } else {
                curr->next = nullptr;
            }
            curr = curr->next;
        }
        return head;
    }
};
