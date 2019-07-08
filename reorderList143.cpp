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
    void reorderList(ListNode* head) {
        vector<int>num;
        for (ListNode* ptr = head; ptr!=NULL; ptr = ptr->next) {
            num.emplace_back(ptr->val);
        }
        int s = 0, e = num.size()-1;
        for (ListNode* ptr = head; ptr!=NULL; s++,e--) {
            ptr->val = num[s];
            if (ptr->next) {
                ptr->next->val = num[e];
                ptr = ptr->next->next;
            } else {
                return;
            }
        }
        return;
    }
};
//the fatest method
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head,* fast = head, *pre=NULL;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        auto left = head;
        auto right = slow;
        if(!pre) return;
        pre->next = NULL;
        cout << pre->val << endl;
        
        auto rightHead = right;
        while(right->next){
            auto temp = right->next;
            right->next=right->next->next;
            temp->next=rightHead;
            rightHead = temp;
        }
        right = rightHead;
        pre = NULL;
        while(left || right){
            if(left){
                if(pre){
                    pre->next=left;
                }
                pre=left;
                left=left->next;
            }
            if(right){
                if(pre){
                    pre->next=right;
                }
                pre=right;
                right=right->next;
            }
        }
    }
};
