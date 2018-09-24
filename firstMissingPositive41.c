int firstMissingPositive(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 1;
    } 
    bool temp[numsSize];
    int min = 0, max = -1;
    for (int i = 0; i < numsSize; i++) {
        temp[i] = false; 
        if (max < nums[i]) {
            max = nums[i];
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < numsSize && nums[i] > 0) {
            temp[nums[i]] = true;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if ( !temp[i] && i > min) {
            return i;
        } 
    }
    if (numsSize == max) {
        return max+1;
    }
    return numsSize;
}
