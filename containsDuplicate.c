//[1,1,1,3,3,4,3,2,4,2]
bool containsDuplicate(int* nums, int numsSize) {
    int i = 0, key;
    if (numsSize == 0){
        return false;
    }
    int map[numsSize];
    for (i = 0; i < numsSize;i++ ) {
        key = abs(nums[i])%numsSize;
        map[key]++;
        if (map[key]>1){
            return true;
        }   
    }  
    return false;
}  

