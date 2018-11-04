// the fatest method
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct ListNode *p,*q,*r;
    p=head;
    q=head->next;
    while(q) {
        if(p->val==q->val){
            r=q;
            p->next=q->next;
            q=q->next;
            free(r);
        }else{
            p=q;
            q=q->next;
        }
    }
    return head;
    
}
//my method
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return;
    }
    int prev = head->val;
    struct ListNode* ptr = head;
    struct ListNode* prh = head;
   //  printf("%d , ", prh->next->next->val);
    while(ptr->next) {
        ptr = ptr->next;
        if (prev != ptr->val) {
            prev = ptr->val;
            prh->next = ptr;
            prh = prh->next;
            //printf("%d , ", prh->val);
        } 
    }
    prh->next = NULL;
    return head;
}
