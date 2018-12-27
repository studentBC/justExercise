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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)return head;
        ListNode*prev , *ptr = head;
        int previous , count = 0;
        for (ptr = head; ptr!=NULL; ptr= ptr->next) {
            count++;
        }
        bool* repeat = (bool*)calloc(count , sizeof(bool));
        if (repeat[0]) cout << " yes it is true" << endl;
        count = 0;ptr = head;
        while (ptr) {
            previous = ptr->val;
            ptr = ptr->next;
            if (ptr) {
                if (ptr->val == previous) {
                    repeat[count] = repeat[count+1]  = true;
                    cout << count << " , " << count+1 <<"    " ;
                }
            }
            count++;
        }
        ptr = head;count = 0;
        while (ptr) {
            if (!repeat[count]) {
                head = ptr;
                break;
            }
            ptr = ptr->next;
            count++;
        }
        cout << endl <<head->val << endl << count+1 << endl;
        prev = head;count++;
        for (ptr = head->next; ptr!=NULL; ptr= ptr->next) {
            if (!repeat[count]) {
                prev->next = ptr;
                prev = ptr;
            }
            count++;
        }
        prev = NULL;
        return head;
    }
};
//the fatest method
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dmy = new ListNode(0);
        dmy->next = head;

        ListNode *prev = dmy;

        while (prev->next) {

            ListNode *curr = prev->next, *p = curr->next;

            while (p && p->val == curr->val) {
                ListNode *tmp = p;
                p = p->next;
                delete tmp;
            }
            
            // p stops at diff node
            if (curr->next == p)
                prev = prev->next;
            else {
                prev->next = p;
                delete curr;
            }
        }

        return dmy->next;
    }
};
