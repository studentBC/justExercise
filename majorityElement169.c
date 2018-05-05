#include<stdio.h>
#include<stdlib.h>
// although it is correct but the fatest algorithm is Boyer–Moore majority vote algorithm
int majorityElement(int* nums, int numsSize) {
   int i ,j= 0;
   int count = 1;
   int half = numsSize/2;
   for(i = 0; i < numsSize;i++){
	   for(j = i+1; j < numsSize;j++){
		   if(nums[i] == nums[j]){
			   count++;
	   			if(count>=half){
		   			return nums[i];
	   			}
		   }
	   }
	   count=1;
   }
   return 0;
}
int main(){
	int array[11] = {-1,3,5,6,99,5,5,5,5,7,8};
	int ans = majorityElement(array,11);
	printf("ans is  %d \n",ans);
	return 0;
}
