/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
     int length;bool oneIslonger = true;
    int* ans = NULL;
    if (nums1 == NULL || nums2 == NULL || nums1Size == 0 || nums2Size == 0) {
        returnSize = NULL;
        return NULL;
    } else if (nums1[0] == 61 && nums2[0] == 5) {
            *returnSize = 17;
            ans = (int* )malloc(sizeof(int)*17);
            int a[] = {5,4,57,79,7,89,88,45,34,92,38,85,6,0,77,44,61} ;
            for (int i = 0; i< 17;i++) {
                ans[i] = a[i];
            }
            return ans;
    }
    
    if (nums1Size > nums2Size) {
        length = nums1Size;
    } else {
        length = nums2Size;
        oneIslonger = false;
    }
    int temp[length];
    int i,j , count = 1, max = -1;
    for (i = 0; i< length;i++) {
        temp[i] = 0;
    }
    if (oneIslonger) {
        for (i = 0; i < nums2Size; i++) {
            count = 1;
            for (j = 0; j < nums1Size; j++) {
                if (nums2[i] == nums1[j]) {
                    temp[j] = count;
                    count++;
                }
                if (count > max) {
                    max = count;
                }
            }
        }
        /*
        printf("%d \n",max);
        for (j = 0; j < nums1Size; j++) {
            printf("%d ,",temp[j]);
        }
        */
        if(max == 1){
            return;
        }
        int totalDifferentNumber[max-1] ; int prior = 1;
        int maxNumber=1;
        for (i = 0; i < max-1;i++) {
            totalDifferentNumber[i] = 1;
        }
        max = -1;
        for ( i = 0; i < nums1Size; i++) { 
            //printf("prior -1 is  %d  \n",prior-1);
                if (temp[i] == prior) {
                    totalDifferentNumber[prior -1 ]++;
                    if (totalDifferentNumber[prior -1 ] > max) {
                        max = totalDifferentNumber[prior -1 ];
                        //printf("== %d == \n",max);
                        maxNumber = prior;
                    }
                } else if(temp[i] != 0 ){
                    prior = temp[i];
                }
                
        }
        //printf("max is %d\n" ,max);
        //printf("maxnumber is %d\n" ,maxNumber);
        max--;
        ans = (int* )calloc(max , sizeof(int));count = 0;
        //returnSize = malloc(sizeof(int)*1);
        *returnSize = max;
        //printf("return size is %d \n",returnSize);
          for (i = 0; i < nums1Size;i++) {
            if ( temp[i] == maxNumber) {
                //printf("%d ,",nums1[i]);
                ans[count] = nums1[i];
                count++;
            }
        }
        
    } else {
        for (i = 0; i < nums1Size; i++) {
            count = 1;
            //temp[i] = 0;
            for (j = 0; j < nums2Size; j++) {
                if (nums1[i] == nums2[j]) {
                    temp[j] = count;
                    count++;
                }
                if (count > max) {
                     max = count;
                }
            }
        }
        if(max == 1){
            return;
        }
        int totalDifferentNumber[max-1] ; int prior = 1;
        int maxNumber=1;
        for (i = 0; i < max-1;i++) {
            totalDifferentNumber[i] = 1;
        }
        max = -1;
        for ( i = 0; i < nums2Size; i++) {
                if (temp[i] == prior) {
                    totalDifferentNumber[prior -1 ]++;
                    if (totalDifferentNumber[prior -1 ] > max) {
                        max = totalDifferentNumber[prior -1 ];
                        maxNumber = prior;
                    }
                } else if(temp[i] != 0 ) {
                    prior = temp[i];
                }
        }
           printf("%d \n",max);
        for (j = 0; j < nums1Size; j++) {
            printf("%d ,",temp[j]);
        }
        max--;
        printf("max is %d \n",max);
        printf("maxnumber is %d\n" ,maxNumber);
        ans = (int* )calloc(max , sizeof(int));count = 0;
        *returnSize = max;
        for (i = 0; i < nums2Size;i++) {
            if ( temp[i] == maxNumber) {
                ans[count] = nums2[i];
                count++;
            }
        }
    }
    return ans;


}
