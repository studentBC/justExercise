int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ans = NULL;
    if (nums1 == NULL || nums2 == NULL || nums1Size == 0 || nums2Size == 0) {
        returnSize = NULL;
        return NULL;
    }
    int i ,j , length,count = 0;
    if (nums1Size > nums2Size) {
        length = nums1Size;
    } else {
        length = nums2Size;
    }
    int* temp = calloc(length,sizeof(int));
    ans = calloc(length,sizeof(int));

    if (nums1Size > nums2Size) {
         for (i = 0; i< nums2Size; i++) {
            for (j = 0; j < nums1Size; j++) {
                if (nums2[i] == nums1[j]) {
                    temp[j]++;
                }
            }
        }
        //for debug
        /*
        for (i = 0; i < length;i++) {
            printf("%d ,", temp[i]);
        }
        printf("\n");
        */
        //end of debug
        count = 0;
        for (i = 0; i < nums2Size ;i++) {
            for ( j = 0; j < nums1Size; j++) {
                if (temp[j] > 0 && nums1[j] == nums2[i]) {
                    printf("%d \n",nums2[i]);
                    ans[count] = nums2[i];
                    temp[j] = 0;
                    count++;
                    break;
                }
            }
        }
    } else {
         for (i = 0; i< nums1Size; i++) {
            for (j = 0; j < nums2Size; j++) {
                if (nums1[i] == nums2[j]) {
                    temp[j]++;
                }
            }
        }
        //for debug
        /*
        for (i = 0; i < length;i++) {
            printf("%d ,", temp[i]);
        }
        printf("\n");
        */
        //end of debug
        count = 0;
        for (i = 0; i < nums1Size ;i++) {
            for ( j = 0; j < nums2Size; j++) {
                if (temp[j] > 0 && nums2[j] == nums1[i]) {
                   // printf("%d \n",nums1[i]);
                    ans[count] = nums1[i];
                    temp[j] = 0;
                    count++;
                    break;
                }
            }
        }
    }
    *returnSize = count;
 
    return ans;


}
//the fatest method
int compare( const void *a, const void *b) {
    if(*(int*)a == *(int*)b)
    {
        return 0;
    }
    else if(*(int*)a < *(int*)b)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    
    int i = 0, j = 0;
    int max;
    if(nums1Size > nums2Size)
    {
        max = nums1Size;
    }
    else
    {
        max = nums2Size;
    }
    int *output = malloc(max*sizeof(int));
    *returnSize = 0;
    
    while (i < nums1Size && j < nums2Size) 
    {
        if (nums1[i] == nums2[j])
        {
            output[(*returnSize)++] = nums1[i];
            ++i;
            ++j;
        }
        else if (nums1[i] < nums2[j])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }
    
    return output;
    free(output);
}
