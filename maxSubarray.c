//fatest method which record max sum when sum < 0 make it to 0 and record again
//it is a smart method
int maxSubArray(int* nums, int numsSize) {
    int max = INT_MIN;
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum > max && sum > 0) {
            max = sum;
        }
        else if (max < nums[i]) {
            max = nums[i];
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    return max;
}
//my method ...  pretty slow ... only beat 13% QAQ...
int maxSubArray(int* nums, int numsSize) {
    int sum = 0 , count = 0, max = INT_MIN, total = 0;bool haspositive = false;
    int positive[numsSize]; 
    if (numsSize == 1) {
        return nums[0];
    }
    for (int i = 0; i < numsSize; i++) {
        sum+=nums[i];
        if (nums[i] > -1) {
            positive[count] = i;
            count++;
            haspositive = true;
        }
        if (max < nums[i]) {
            max = nums[i];
        }
    }
    if (count == numsSize) {
        return sum;
    } else if (!haspositive) {
        return max;
    } else {
        printf("numsSize is %d \n", numsSize);
        for (int i = 0; i < count; i++) {
            for (int j = i; j < count; j++) {
                total = 0;
                for (int start = positive[i]; start <= positive[j]; start++) {
                    //printf("%d ,",nums[start]);
                    total+=nums[start];
                }
                //printf("\n");
                if (total > max) {
                    max = total;
                }
            }
        }
    }
    return max;
}
