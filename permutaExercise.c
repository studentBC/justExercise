#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permutation(int *a,int start , int end, int ** ans, int count)
{
   int i;
   if (start == end) {
	   for (i = 0; i < end; i++) {
       		ans[count][i] = a[i];
     		printf("%d ,", ans[count][i]);
	   }
	   printf("count is %d \n", count);
   }
   else
   {
       for (i = start; i <= end; i++)
       {
          swap(&a[start], &a[i]);
          permutation(a, start+1, end , ans, count+1);
          swap(&a[start], &a[i]); //backtrack
       }
   }
}

int** permute(int* nums, int numsSize, int* returnSize) {
       int i = 0; double size = 1;
       for (i = numsSize; i > 0; i--) {
            size*=i;
       }
       *returnSize = size;
       int** ans = (int**)malloc(size*sizeof(int*));
       for (i = 0; i < size; i++) {
           ans[i] = (int*)malloc(numsSize*sizeof(int));
       }
	   int count = 0;
       permutation(nums,0,numsSize,ans, count);
    
    return ans;
}
int main() {
	int input[] = {1,2,3};
	int* returnsize;
	int** ans = permute(input , 3 , returnsize);
	int i = 0, j;
	printf("=====   return size is %d =====\n", *returnsize);
	for (i = 0; i < *returnsize; i++) {
		for (j = 0; j < 3 ;j++) {
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
