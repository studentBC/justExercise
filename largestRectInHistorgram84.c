int largestRectangleArea(int* heights, int heightsSize) {
    if (heightsSize == 0) {
        return 0;
    }
    printf("height is %d \n",heightsSize);
    int max = -1 ,  min = INT_MAX;
    double sum = 0 ;
    for (int i = 0; i < heightsSize; i++) {
        if (max < heights[i]) {
            max = heights[i];
        }
        //sum+=heights[i];
        if (heights[i]!=0 && min > heights[i]) {
            min = heights[i];
        }
    }
    //printf("min is %d max is %d \n",min,max);
    /*
    if (sum == max) {
        return max;
    }
    */
    int ans = 0, regionMax = -1;
    for (double i = min; i <= max; i++) {
        sum = 0;regionMax = -1;
        for (int j = 0; j < heightsSize; j++) {
            if (heights[j] >= i) {
                sum+=i;
            } else {
                sum = 0;
            }
            if (regionMax < sum) {
                    regionMax = sum;
            }
        }
        //printf("at region %d its max is %d \n",i,regionMax);
        if (ans < regionMax) {
            ans = regionMax;
        }
    }
    return ans;
}
