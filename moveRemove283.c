/*
 *
 * Input: [0,1,0,3,12]
	Output: [1,3,12,0,0]
 *
 *
 */
int hasNonZero(int start , int* nums, int numsSize){
	int i= 0;
	for(i = start;i < numsSize;i++){
		if(nums[i]!=0) {
			return i;
		}
	}
	return -1;
}
void moveZeroes(int* nums, int numsSize) {
	int i = 0,j;int notzero;bool notfoundzero = true;int temp;
	for (i = 0; i < numsSize;i++) {
		if( nums[i] == 0) {
			notzero = hasNonZero(i,nums,numsSize);
			if (notzero > 0){
				nums[i] = nums[notzero];
				nums[notzero] = 0;
			}
		}
	}
	return;
}

//the fatest method
void moveZeroes(int* nums, int numsSize) {
    int i = 0;
    
    int start=0, end=0, numZero=0;
    
    if (nums == NULL || numsSize == 0)
        return;
    
    while (i < numsSize) {
        //skip all the non zero numbers
        while (i < numsSize && nums[i] != 0) i++;
        if (i == numsSize) return;
        
        //remember the current zero number pos
        start = i;
        
        //skil all the zero after this
        while (i < numsSize && nums[i] == 0) i++;
        
        if (i == numsSize) return;
        end = i;
   
        // move the next end - start  + 1 non zero numbers over
        int j = start;
        
   //    printf("i=%d, start=%d, end=%d\n", i, start, end);
        
        while (i < numsSize && nums[i] != 0 && j <=end) {
       //    printf("move i=%d, j=%d\n", i, j);
            nums[j++] = nums[i];
            nums[i++] = 0;
            start++;
            
        }
        
        i = start;
        
    }
    /*
    // fill the rest to zeros.
    int j = numsSize - 1;
    while (numZero != 0) {
        nums[j--] = 0;
        numZero--;
    }
    */
}
