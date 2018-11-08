int Sum(int* nums, int start, int end) {
    int s = 0;
    for (int i = start; i <= end; i++) {
        s+=nums[i];
    }
    return s;
}
int maxSubArray(int* nums, int numsSize) {
    int sum , max = INT_MIN , count = 0;
    int positive[numsSize];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            positive[count] = i;
            count++;
        }
        if (max < nums[i]) {
            max = nums[i];
        }
    }
    if (max <=0) {
        return max;
    }
    int start = positive[0];
//  max = INT_MIN;
//  using a sliding window to get sum the maximum plane length is count
    int pale = positive[count-1] - positive[0] +1 , end;
    for (int i = 0; i < pale; i++) {
        start = positive[0];
        end = start+i;
        sum = Sum(nums,start, end);
		if (max < sum) {
                max = sum;
        }
		//printf("start: %d  end: %d  sum: %d \n",start,end,sum);
        for (int j = 1; j < pale-i; j++) {
            sum-=nums[start];
            end++;
            start++;
            sum+=nums[end];
            if (max < sum) {
                max = sum;
            }
        }
        
    }
    return max;
}
//the fatest method
#define MAXX(x, y)  ((x) > (y) ? (x) : (y))

int maxSubArray(int* nums, int numsSize) {
    int i;
    int max_sum;
    int cur_sum;
    
    if (numsSize == 0) {
        return (0);
    }
    
    if (numsSize == 1) {
        return (nums[0]);
    }
    
    max_sum = nums[0];
    cur_sum = nums[0];
    
    for (i = 1; i < numsSize; i++) {
        cur_sum = MAXX(nums[i], cur_sum + nums[i]);
        max_sum = MAXX(cur_sum, max_sum);
#ifdef MYDEBUG        
        printf("cur_sum[%d]=%d\n", i, cur_sum);
        printf("max_sum[%d]=%d\n", i, max_sum);
#endif
    }
    
    return (max_sum);
}
