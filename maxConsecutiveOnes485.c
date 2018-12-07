int findMaxConsecutiveOnes(int* nums, int numsSize) {
	int count = 0, max = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == 0) {
			count = 0;
		} else {
			count++;
		}
		if (max < count)max = count;
	}
	return max;
}
//the fatest method
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int i = 0;
    int start=0, end=0, reVal=0;
    for(i=0; i<numsSize; i++){
        if(nums[i]==1){
            start = i;
            end = i;
            while(end<numsSize && nums[end]==1){
               end = end+1;
            }//while
            i = end;
            if((end-start)>reVal)
                reVal = end-start;
        }//if
    }//for
    return reVal;
}
