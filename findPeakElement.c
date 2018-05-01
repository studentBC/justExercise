#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int findPeakElement(int* nums, int numsSize) {
    int start = 1;
    if(numsSize == 1){
        return 0;
    }else if(numsSize == 2){
        if(nums[0]>nums[1]){
            return 0;
        }else{
            return 1;
        }
    }
    else{
        if(nums[0]>nums[1]){
            return 0;
        }else if(nums[numsSize-1] > nums[numsSize-2]){
            return numsSize-1;
        }else{
            for(start = 1;start <= numsSize -2;start++){
                if(nums[start]>nums[start-1] && nums[start]>nums[start+1]){
                    return start;
                }
            }
        }
    }
     return -INT_MIN;
}
int main(){
	int num[7] = {1,2,1,3,5,6,4};
	printf("we have found that index  %d \n",findPeakElement(num,7));	
}
