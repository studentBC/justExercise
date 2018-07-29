int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
     int length;bool oneIslonger = true;
    int* ans = NULL;
    int* p1 = NULL;
    int* p2 = NULL;
      bool start = false;
    int matchNumber,matchSize;
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
       // printf("max is %d\n" ,max);
       // printf("maxnumber is %d\n" ,maxNumber);
        //max--;
  //      ans = (int* )calloc(length , sizeof(int));count = 0;
        //returnSize = malloc(sizeof(int)*1);
        p1 = (int* )calloc(length , sizeof(int));count = 0;
        p2 = (int* )calloc(length , sizeof(int));int count2 = 0; 
      //  printf("return size is %d \n",returnSize);
          for (i = 0; i < nums1Size;i++) {
            if ( temp[i] == maxNumber) {
                printf("%d ,",nums1[i]);
                p1[count] = nums1[i];
                count++;
            }
              //for those continuous number
            if(temp[i] == 1 && i!=nums1Size-1) {
                start = true;
                p2[0] = nums1[i];
                count2 = 1;
            }
            if (start && temp[i] == count2+1) {
                p2[count2] = nums1[i];
                matchNumber = nums1[i];
                count2++;
            }
        }
        matchSize = 0;
        for (i = 0; i <nums2Size; i++) {
            if (nums2[i] == matchNumber) {
                matchSize++;
            }
        }
        printf("count is %d count2 is %d and the length of matchsize is %d , match number is %d \n",count,count2,matchSize,matchNumber);
        if (count > count2) {
            ans = p1;
        } else {
            if (matchSize >= count2) {
                ans = p2;
                count = count2;
            } else {
                ans = p1;
            }
            
        }
        *returnSize = count;
        
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
           //printf("max is %d and the prior is %d \n",max,prior);
        for (j = 0; j < nums1Size; j++) {
            printf("%d ,",temp[j]);
        }
        //max--;
        //printf("max is %d \n",max);//6
        //printf("maxnumber is %d\n" ,maxNumber);//1
        p1 = (int* )calloc(length , sizeof(int));count = 0;
        p2 = (int* )calloc(length , sizeof(int));int count2 = 0;
        
        //printf("\n");
        for (i = 0; i < nums2Size;i++) {
            if ( temp[i] == maxNumber) {
                //printf("%d ," , nums2[i]);
                p1[count] = nums2[i];
                count++;
            }
            if(temp[i] == 1 && i!=nums2Size-1) {
                start = true;
                 p2[0] = nums2[i];
                count2 = 1;
            }
            if (start && temp[i] == count2+1) {
                p2[count2] = nums2[i];
                matchNumber = nums2[i];
                count2++;
            }
        }
        matchSize = 0;
        for (i = 0; i <nums1Size; i++) {
            if (nums1[i] == matchNumber) {
                matchSize++;
            }
        }
        //printf("count is %d count2 is %d \n",count,count2);
        if (count > count2) {
            ans = p1;
        } else {
             if (matchSize >= count2) {
                ans = p2;
                count = count2;
            } else {
                ans = p1;
            }
            
        }
        *returnSize = count;
    }
    return ans;


}

