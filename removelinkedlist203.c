#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
   	struct ListNode *next;
};
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* searchPosition = head;
	struct ListNode* beforeSearchPosition = head;
	int count = 0;
	//move the serchposition , beforesearchposition and remain head
	do{
		if(searchPosition->val == val){
			//find the first element in the first one
			if(count == 0){
				head=head->next;
			}else if( searchPosition->next == NULL){ //find the val in the last one
				beforeSearchPosition->next = NULL;	
			}else{
				beforeSearchPosition->next = searchPosition->next;	
			}

		}
		count++;
		beforeSearchPosition = searchPosition;
		if(searchPosition->next!=NULL){
			searchPosition = searchPosition->next;
		}
	}while(searchPosition != beforeSearchPosition);
	return head;
}
int main(){
	struct ListNode linkedlist[7];
	int j = 0;
	for(j = 0; j < 6;j++){
		linkedlist[j].val=j;
		linkedlist[j].next = &linkedlist[j+1];
	}
	linkedlist[6].val = 1;
	int delete;
	printf(" enter a number and i will help you delete in your linkedlist \n");
	scanf("%d",&delete);
	struct ListNode* ans = removeElements(linkedlist,delete); 
	printf(" .... done .... and the # in your list are ....\n");
	int i = 0;
	while(ans!=NULL){
		//printf("%d \n",linkedlist[i].val);
		printf("%d  -> ",ans->val);
		ans = ans->next;
	}
	printf(" \n");
 	return 0;
}
