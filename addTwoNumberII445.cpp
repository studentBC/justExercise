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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1, *ptr2 = l2, *ans = (ListNode*)malloc(sizeof(ListNode));
        vector<int>one , two;
        while (ptr1) {
            one.push_back(ptr1->val);
            ptr1 = ptr1->next;
        }
        while (ptr2) {
            two.push_back(ptr2->val);
            ptr2 = ptr2->next;
        }
        bool forward = false;
        int j , number;
        if (one.size() > two.size()) {
            j = one.size() -1;
            for (int i = two.size()-1; i > -1 ; i--) {
                if (forward) {
                    number = one[j]+1;
                } else {
                    number = one[j];
                }
                number+=two[i];
                if (number >= 10) {
                    one[j] = number-10;
                    forward = true;
                } else {
                    one[j] = number;
                    forward = false;
                }
                j--;
            }
            for (;j> -1; j--) {
                if (forward) {
                    number = one[j]+1;
                } else {
                    number = one[j];
                    break;
                }
                if (number >= 10) {
                    one[j] = number-10;
                    forward = true;
                } else {
                    one[j] = number;
                    forward = false;
                }
            }
            ptr1 = ans;
            if (forward) {
                ans->val = 1;
                ptr1->next = (ListNode*)malloc(sizeof(ListNode));
                ptr1 = ptr1->next;
            }
            j = 0;
            for (int i = 0; i < one.size(); i++) {
                ptr1->val = one[i];
                if (i < one.size() -1) {
                    ptr1->next = (ListNode*)malloc(sizeof(ListNode));
                    ptr1 = ptr1->next;
                } else {
                    ptr1->next = NULL;
                }
            }
        } else {
            j = two.size() -1;
            for (int i = one.size()-1; i > -1 ; i--) {
                if (forward) {
                    number = two[j]+1;
                } else {
                    number = two[j];
                }
                number+=one[i];
                if (number >= 10) {
                    two[j] = number-10;
                    forward = true;
                } else {
                    two[j] = number;
                    forward = false;
                }
                j--;
            }
            for (;j> -1; j--) {
                if (forward) {
                    number = two[j]+1;
                } else {
                    number = two[j];
                    break;
                }
                if (number >= 10) {
                    two[j] = number-10;
                    forward = true;
                } else {
                    two[j] = number;
                    forward = false;
                }
            }
            ptr1 = ans;
            if (forward) {
                ans->val = 1;
                ptr1->next = (ListNode*)malloc(sizeof(ListNode));
                ptr1 = ptr1->next;
            }
            j = 0;
            for (int i = 0; i < two.size(); i++) {
                ptr1->val = two[i];
                if (i < two.size() -1) {
                    ptr1->next = (ListNode*)malloc(sizeof(ListNode));
                    ptr1 = ptr1->next;
                } else {
                    ptr1->next = NULL;
                }
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        
        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        int sum = 0;
        
        stack<int> s3;
        
        while(!s1.empty() || !s2.empty())
        {
            int num1 = 0;
            int num2 = 0;
            sum = 0;
            if(!s1.empty())
            {
                num1 = s1.top();
                s1.pop();
            }
            
            if(!s2.empty())
            {
                num2 = s2.top();
                s2.pop();
            }
            
            sum = num1 + num2 + carry;
            if(sum >= 10)
            {
                carry = 1;
                sum = sum%10;
            }
            else
            {
                carry = 0;
            }
            
            s3.push(sum);
        }
        
        if(carry != 0)
        {
            s3.push(carry);
        }
        
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while(!s3.empty())
        {
            tail->next = new ListNode(s3.top());
            s3.pop();
            tail = tail->next;
        }
        
        return head->next;
    }
};
