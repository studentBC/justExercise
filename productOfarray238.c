/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int)*numsSize);
    int p = 1 , j ,temp = 1;
    for (int i = 0; i < numsSize; i++) {
        p*=nums[i];
    }
    for (int i = 0; i < numsSize ; i++) {
        if (nums[i] == 0) {
            for (j = i+1 ;j < numsSize ; j++) {
                temp*=nums[j];
            }
            for (j = i-1 ; j > -1 ;j-- ) {
                temp*=nums[j];
            }
            ans[i] = temp;
            temp = 1;
        } else {
            ans[i] = p/nums[i];
        }  
    }
    *returnSize = numsSize;
    return ans;
}  
