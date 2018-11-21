/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int*ans = malloc(sizeof(int)*numsSize);
    int index;
    for (int i = 0; i < numsSize; i++) {
        ans[i] = -1;
        index = i+1;
        if (index == numsSize)index = 0;
        while(index!=i) {
            if (nums[index] > nums[i]) {
                ans[i] = nums[index];
                break;
            }  
            index++;
			if (index>=numsSize)index-=numsSize;
        }  
    }   
    return ans;
}  
//the fatest method
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
    int* res = (int*)malloc(numsSize * sizeof(int));
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;
    for (int i = 0; i < numsSize; ++i)
    {
    	while(top != -1 && nums[i] > nums[stack[top]])
    		res[stack[top--]] = nums[i];
		stack[++top] = i;
   	}

   	for (int i = 0; i < numsSize - 1; ++i)
   		while(top != -1 && nums[i] > nums[stack[top]])
    		res[stack[top--]] = nums[i];
    	
   	while(top != -1)
   		res[stack[top--]] = -1;

   	free(stack);
   	return res;
}
