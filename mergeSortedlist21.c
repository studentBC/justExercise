/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p1 = NULL;
    struct ListNode* ans = NULL;
    if (l1 == NULL && l2 != NULL) {
        return l2;
    } else if (l1!= NULL && l2 == NULL){
        return l1;
    }else if (l1 == NULL && l2 == NULL){
        return NULL;
    }
    if (l1->val<l2->val) {
        ans = l1;
        p1 = ans;
        l1 = l1->next;
    } else{
        ans = l2;
        p1 = ans;
        l2 = l2->next;
    }
    while (l1 != NULL || l2!= NULL) {
          if (l1 != NULL && l2 != NULL){
              if (l1->val < l2->val){
                  ans -> next = l1;
                  l1 = l1->next;
              } else{
                  ans -> next = l2;
                  l2 = l2->next;
              }
          } else if (l1 == NULL && l2 != NULL) {
              ans->next = l2;
              l2 = l2->next;
          } else if (l1 != NULL && l2 == NULL) {
              ans ->next = l1;
              l1 = l1->next;
          }
        ans = ans->next;
    }
    return p1;
    
}
