//the fatest method
int singleNumber(int* nums, int numsSize) {
    int x = 0;
    while (numsSize--) x ^= nums[numsSize];
    return x;
}

//my slowest method
int singleNumber(int* nums, int numsSize) {
    int i ,j,count = 0;
    for (i = 0; i < numsSize;i++){
        for(j = 0; j < numsSize;j++){
            if(nums[i] == nums[j]){
                count ++;
                if(count == 2){
                    break;
                }
            }
        }
        if(count == 1){
            return nums[i];
        }
        count = 0;
    }
    return NULL;
}
