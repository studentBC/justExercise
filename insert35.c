int searchInsert(int* nums, int numsSize, int target) {
    int h=0, t=numsSize-1, m;
    while(h<=t) {
        m = (h+t)/2;
        if(nums[m] > target) {
            t = m-1;
        } else if(nums[m] == target) {
            return m;  
        } else {
            h = m+1;
        }
    }
    return h;
}
