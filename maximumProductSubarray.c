//the fatest method
int maxProduct(int *nums, int numsSize) {
        assert(numsSize > 0);
        int i, j, maxval = nums[0], curval = 1, previ = 0, changed = 0;
        for (i = 0; i < numsSize; i++) {
                if (nums[i] != 0) {
                        curval *= nums[i];
                        maxval = (curval > maxval) ? curval : maxval;
                        continue;
                }
                for (j = previ; j < (i-1) && curval < 0; j++) {
                        curval /= nums[j];
                        changed = 1;
                }
                maxval = (maxval < 0) ? 0 : maxval;
                if (changed)
                    maxval = (curval > maxval) ? curval : maxval;
                curval = 1;
                previ = i+1;
                changed = 0;
        }
        for (j = previ; j < (i-1) && curval < 0; j++) {
                changed = 1;
                curval /= nums[j];
        }
        if (changed)
            maxval = (curval > maxval) ? curval : maxval;
        return (maxval);
}
//my brutal force method
int maxProduct(int* nums, int numsSize) {
    int max = INT_MIN;
    double product = 1;
    //printf("size is %d \n",numsSize);
    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            product = 1;
            //printf("i: %d, j: %d \n",i,j);
            for (int start = i; start <=j; start++) {
                product*=nums[start];
            }
            //printf("%lf \n",product);
            if(max < product) {
                max = product;
            }
        }
    }
    return max;
}
