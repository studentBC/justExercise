#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
      struct ListNode *next;
  };

struct ListNode *detectCycle(struct ListNode *head) {
	    ListNode * m1,m2 = head;
		bool Isloop = false;
		while(m1 && m2 && m2->next){
			m1 = m1->next;
			m2=m2->next->next;
			if(m1 == m2){
				Isloop = true;
				break;
			}
		}
		if(Isloop == true){
			m1 = head;
			while(m1!=m2){
				m1 = m1->next;
				m2 = m2->next->next;
			}
			return m1;
		}else{
			return NULL;
		}


}
int main(){
}
