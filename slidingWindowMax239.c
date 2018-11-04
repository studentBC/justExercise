/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0) {
        return NULL;
    }
    *returnSize = numsSize - k +1;
    int* ans = malloc(*returnSize*sizeof(int));
    int max = INT_MIN;
    for (int i = 0; i < *returnSize; i++) {
        max = INT_MIN;
        for (int j = i; j < k+i; j++) {
            if (max < nums[j]) {
                max = nums[j];
            }
        }
        ans[i] = max;
    }
    return ans;
}
//the fatest method
int getMax(int*, int);
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if(numsSize == 0) return NULL;
    
    *returnSize = numsSize - k + 1;
    int *result = (int *)malloc(*returnSize * sizeof(int));
    int i; 
    printf(" K :%d\n", k);
    
    result[0] = getMax(nums, k);
//for(i =0; i<numsSize;i++)
   printf(" result[0]: %d\n",result[0]);
    for(i = 1; i <= numsSize - k; i++) {
        if(nums[i + k - 1] > result[i - 1]) 
            result[i] = nums[i + k - 1];
        else if(nums[i - 1] == result[i - 1])
            result[i] = getMax(nums + i, k);
        else 
            result[i] = result[i - 1];
    }
    return result;
}

int getMax(int* nums, int size) {
    int tmp = *nums;
    int i;
    for(i = 1; i < size; i++)
        if(tmp < nums[i]) tmp = nums[i];
    return tmp;
}
