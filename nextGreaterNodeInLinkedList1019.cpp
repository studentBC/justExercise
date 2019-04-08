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
    vector<int> nextLargerNodes(ListNode* head) {
        struct ListNode * i, *j;
        bool found;
        vector<int>ans;
        for (i = head; i!=NULL; i=i->next) {
            found = false;
            for (j = i->next; j!=NULL; j=j->next) {
                if (j->val > i->val) {
                    ans.push_back(j->val);
                    found = true;
                    break;
                }  
            }   
            if (!found) ans.push_back(0);
        }
        return ans;
    }
};
//the fatest method
class Solution {
   public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> stk;
        for (; head != nullptr; head = head->next) {
            ans.emplace_back(head->val);
        }
        for (int i = ans.size() - 1; i >= 0; --i) {
            for (; !stk.empty() && stk.top() <= ans[i]; stk.pop())
                ;
            int val{0};
            if (!stk.empty()) {
                val = stk.top();
            }
            stk.emplace(ans[i]);
            ans[i] = val;
        }
        return ans;
    }
};
