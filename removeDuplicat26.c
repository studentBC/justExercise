int removeDuplicates(int* nums, int numsSize) {
  int i = 0,count = 0,dupos = 0;
    int prev = -77;bool foundD = true;
    for( i = 0; i < numsSize;i++ ) {
        if (nums[i] != prev) {
            prev = nums[i];
            nums[count] = nums[i];
            count++;
        } 
    }
    return count;
}
int main(){
	int nums[10] = {0,0,1,1,1,2,2,3,3,4};
	printf("%d \n", removeDuplicates(nums,10));
	return 0;
}
