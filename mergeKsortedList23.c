/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 *
 * my method beat 55.57 %
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int start;
    if (listsSize == 0) {
        return NULL;
    } else {
        for (int j = 0; j < listsSize; j++) {
            if (lists[j]) {
                start = j;
                break;
            }
        }
    }
    bool go;
    //printf("we start from %d \n",start);
    struct ListNode* m = lists[start],* mpre = lists[start]; //merged
    struct ListNode* M = NULL,* Mpre = NULL;  //merging others
    for (int i = start+1; i < listsSize; i++) {
        M = Mpre = lists[i];
        m = mpre = lists[start];
        while(M) {
            go = true;
            //printf("M: %d , m: %d \n",M->val,mpre->val);
            if (mpre->next) {
                if (M->val>=mpre->val && M->val <= mpre->next->val) {
                    Mpre = M;
                    M = M->next;
                    Mpre->next = mpre->next;
                    mpre->next = Mpre;     
                } else if (M->val < mpre->val) {
                    Mpre = M;
                    M = M->next;
                    Mpre->next = mpre;
                    lists[start] = m = mpre = Mpre;
                    go = false;
                }
            } else {
                if (M->val>=mpre->val) {
                    Mpre = M;
                    M = M->next;
                    Mpre->next = NULL;
                    mpre->next = Mpre;     
                } else {
                    Mpre = M;
                    M = M->next;
                    Mpre->next = mpre;
                    lists[start] = m = mpre = Mpre;
                    go = false;
                }
            }
            if (mpre->next && go) {
                mpre = mpre->next;
            }
            
        }
    }
    return m;
}
//fatest method combine with sorting algs , pretty smart ! 
typedef struct ListNode list;

list * merge_two_lists(list *l1, list *l2){
  if(l2==NULL){
        return l1;
    }
    if(l1==NULL){
        return l2;
    }
    
    if(l1->val < l2->val){
        l1->next = merge_two_lists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = merge_two_lists(l1, l2->next);
        return l2;
    }
}

list *merge(list* lists[], int start, int end){
  if(start>end){
    return NULL;
  }
  else if(start==end){
    return lists[start];
  }
  
  int middle = (start+end)/2;
  
  list *first = merge(lists, start, middle);
  list *second = merge(lists, middle+1, end);
  
  return merge_two_lists(first, second);
  
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    return merge(lists, 0, listsSize-1);
}
