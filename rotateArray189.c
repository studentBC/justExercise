void rotate(int* nums, int numsSize, int k) {
    while (k > numsSize){
        k-=numsSize;
    }
    int start = numsSize - k;
    int temp[numsSize];int count = 0;int i;
    for ( i = start; i < numsSize;i++){
        temp[count] = nums[i];
        count ++;
    }
    for(i = 0; i < start;i++) {
        temp[count] = nums[i];
        count++;
    }
    for(i =0;i<numsSize;i++) {
        nums[i] = temp[i];
    }
    return ;
}
