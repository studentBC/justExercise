void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void permutation(int *a, int start, int end,int** ans,int* count)
{
   int i;
   if (start == end) { 
       for (i = 0; i <= end; i++) {
           printf("%d , ",a[i]);
            ans[*count][i] = a[i];
       }
       printf("\n");
       *count = *count+1;
       return ;
   }
   else
   {
       for (i = start; i <= end; i++)
       {
          swap((a+start), (a+i));
          permutation(a, start+1, end , ans, count);
          swap((a+start), (a+i)); //backtrack
       }
   }
}
//definition
int** permute(int* nums, int numsSize, int* returnSize) {
       int i = 0; int size = 1;
       for (i = numsSize; i > 0; i--) {
           //printf("i is %d \n",i);
            size = i*size;
       }
       *returnSize = size;
        printf("size is %d \n",size);
       int** ans = (int**)calloc(size , sizeof(int*));
       //printf("numssize is %d \n",numsSize);
       for (i = 0; i < size; i++) {
           ans[i] = (int*)calloc(numsSize , sizeof(int));
       }
    /*
        if(numsSize == 1) {
            ans[0][0] = nums[0];
            printf("enter now !");
            return ans;
        }
        */
    int* count = malloc(sizeof(int));
    *count = 0;
       permutation(nums,0,numsSize-1,ans,count);

       return ans;
}

