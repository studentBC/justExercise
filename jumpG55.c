#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool jump(int* nums, int pos ,int  prevpos , int end) {
    int step = nums[pos];
                //printf("0. step is %d \n", step);
    if (pos + step >= end) {
        return true;
    } 
        prevpos = pos;
        //pos+=step;
    for (int i = step; i > 0; i--) {
        //printf("pos is %d ,   prevpos is %d   , step is %d \n", pos , prevpos , step);
        if ( jump(nums,pos+i,prevpos,end) ) {
            return true;
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
//fatest method without using recursive
bool canJump(int* a, int n) {
    if(n==1)
        return true;
    if(a[0]==0)
        return false;
    int h = n-2;
    while(h>=0)
    {
    while(h>0)
    {
        if(a[h]>0)
            h--;
        else
            break;
    }
    if(h==0)
        return true;
    int k = 2;
    h=h-1;
    bool skip=false;
    while(h>=0)
    {
        if(a[h]>=k)
        {
            skip=true;
            break;
        }
        h--;
        k++;
    }
    if(skip==false)
        return false;
    }
    return false;
}
