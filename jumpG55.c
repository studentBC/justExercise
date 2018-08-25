#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool jump(int* nums, int pos ,int  prevpos , int end) {
    int step = nums[pos];
		printf("0. step is %d \n", step);
    if (pos + step >= end) {
        return true;
    } else if (step > 0) {
		prevpos = pos;
        pos+=step;
		printf("1. pos is %d and its step is %d \n", pos , nums[pos]);
        if ( jump(nums,pos,prevpos ,end) ) {
            return true;
        }
		printf("2. prev pos is %d \n", prevpos);
		if (nums[prevpos]-1 > 0) {
			nums[prevpos]--;
			pos = prevpos + nums[prevpos] ;
            if (jump(nums,pos,prevpos,end) ) {
				return true;
			}
        } else {
            return false;
        }
        
    }
   return false; 
    
}
bool canJump(int* nums, int numsSize) {
    if (numsSize == 1 && nums[0] == 0) {
        return true;
    }
    return jump(nums,0,0,numsSize-1);
}
int main() {
	int nums[3] = {1,0,1};
	if ( canJump(nums,3) ) {
		printf(" yes , it can jump there ! \n" );
	} else {
		printf(" no , it can't ! \n" );
	}
	return 0;
}
