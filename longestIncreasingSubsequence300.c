#define max(x,y)         (x > y?x:y)
int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int count[numsSize], maxcount;
    int ans = 1;
    count[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        maxcount = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                maxcount = max(count[j],maxcount);
            }  
            count[i] = maxcount+1;
            if (count[i] > ans) {
                ans = count[i];
            }  
        }  
    }  
    return ans;
}
//the fatest method
int binarySearch(int *nums, int left, int right, int n) {
    
    int size = right-left+1;        
    int idx;
    int mid;
    //printf("insert %d into dp, left=%d, right=%d, size=%d, mid=%d\n", n, left, right, size, left+size/2);
    //printArray(nums, right+1);
    
    while (left <= right) {
        size = right-left+1;
        mid = left + size/2;
        if (nums[mid]==n) return mid;
        else if (n>nums[mid]) left = mid+1;
        else if (n<nums[mid]) right = mid-1;        
    }
    
    return nums[mid]<n ? -(mid+1) : -mid;
}

void printArray(int *nums, int numsSize) {
    printf("[");
    for (int i=0; i<numsSize; i++) {
        printf("%d,", nums[i]);
    }
    printf("]\n");
}

int lengthOfLIS(int *nums, int numsSize) {
    
    if (numsSize==0) return 0;
    if (numsSize==1) return 1;
    if (numsSize==2) return 1+(nums[0]<nums[1]);
    
    int dp[numsSize];
    dp[0] = nums[0];
    int len = 1;
    int insertIdx;
    
    for (int i=0; i<numsSize; i++) {
        //printf("dp is:");
        //printArray(dp, len);
        insertIdx = binarySearch(dp, 0, len-1, nums[i]);
        insertIdx = insertIdx < 0 ? -insertIdx : insertIdx;
        //printf("insertIdx for %d is %d\n", nums[i], insertIdx);
        dp[insertIdx] = nums[i];
        len += (insertIdx==len);
    }
    return len;
}
