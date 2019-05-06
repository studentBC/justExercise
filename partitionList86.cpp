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
    ListNode* partition(ListNode* head, int x) {
        vector<int>small;
        vector<int>el;
        for (ListNode* ptr = head; ptr!=NULL; ptr = ptr->next) {
            if (ptr->val < x) {
                small.emplace_back(ptr->val);
            } else {
                el.emplace_back(ptr->val);
            }
        }
        //sort(small.begin(), small.end());
        ListNode* ptr = head;
        for (int i = 0; i < small.size(); i++) {
            ptr->val = small[i];
            ptr = ptr->next;
        }
        for (int i = 0; i < el.size(); i++,ptr = ptr->next) {
            ptr->val = el[i];
        }
        return head;
    }
};

