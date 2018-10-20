int removeElement(int* nums, int numsSize, int val) {
    int count = 0;
    if (numsSize == 1) {
        if (nums[0] == val) {
            return 0;
        } else {
            return 1;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            count++;
        }  
    }
    for (int i = 0; i < numsSize -1 ; i++) {
        if (nums[i] == val) {
            for (int j = i+1; j < numsSize; j++) {
                if (nums[j]!=val) {
                    nums[i] = nums[j];
                    nums[j] = val;
                    break;
                }
            }
        }
    }
    return numsSize - count;
}  
