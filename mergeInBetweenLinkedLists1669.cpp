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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count = 0;
        ListNode* end = list2,*front = NULL, *back = NULL;
        while (end->next != NULL) {
            end = end->next;
        }
        //cout << end->val <<" , ";
        for (ListNode* ptr = list1; ptr != NULL; ptr = ptr->next) {
            if (count + 1 == a) {
                front = ptr;
            }
            if (count == b + 1) {
                back = ptr;
                break;
            }
            count++;
        }
        front->next = list2;
        end->next = back;
        return list1;
    }
};
//the fatest solution
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
    typedef struct ListNode *lptr;
    
    
    ListNode* mergeInBetween(ListNode* L, int a, int b, ListNode* L1) {
        lptr P1=L;int x=1;a--;
        while(P1->next&&x<=a)
        {
            P1=P1->next;x++;
        }
        b=b-a;
        int y=1;
        lptr P2=P1;
        while(P2&&y<=b)
        {
            P2=P2->next;y++;
        }P2=P2->next;
        P1->next=L1;
        while(L1->next)L1=L1->next;
        L1->next=P2;
        return L;
    }
};
