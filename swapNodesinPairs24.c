/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void swap(int* a , int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL) {
        return ;
    }
    struct ListNode* ptr = head;
    int count = 1;
    int temp[1024];
    temp[0] = ptr->val;
    while (ptr->next) {
        ptr=ptr->next;
        temp[count] = ptr->val;
        printf("%d ,", temp[count]);
        count++;
    }
    //printf("\n count is %d \n",count);
    int i;
    ptr = head; 
    //printf("ola ola \n");
    if (count%2 == 0) {
         //printf("ola ola \n");
        for (i = count-1; i > 0; i-=2) {
            swap(&temp[i] , &temp[i-1]);
        }
        
        for (i = 0; i < count ; i++) {
            ptr->val = temp[i];
            //printf(" %d , ",temp[i]);
            ptr = ptr->next;
        }
    } else {
        for (i = count-2; i > 0; i-=2) {
            swap(&temp[i] , &temp[i-1]);
        }

        for (i = 0; i < count ; i++) {
            ptr->val = temp[i];
            ptr = ptr->next;
        }
    }
    
    return head;
}
