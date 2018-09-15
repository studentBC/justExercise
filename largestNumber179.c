void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
bool compare(int inum, int jnum, int ifront, int jfront , int inumberOfdigits , int jnumberOfdigits) {
    int fronti , frontj;
    if (ifront < jfront) {
        return true;
    } else if (ifront == jfront) {
        if (inumberOfdigits == jnumberOfdigits) {
            if (inum < jnum) {
                //printf("inum is %d , jnums is %d \n",inum , jnum);
                return true;
            } else {
                return false;
            }
        } else {
            fronti = jnum + inum*pow(10,jnumberOfdigits);
            frontj = inum + jnum*pow(10,inumberOfdigits);
            if (fronti > frontj ) {
                return false;
            } else {
                return true;
            }
                
        }
    }
    return false;
}
int getfront(int n ) {
    while(n>=10) {
        n/=10;
    }
    return n;
}

int getDigit(int n , int* front ) {
    int count = 1;
    while(n>=10) {
        n/=10;
        count++;
    }
    *front = n;
    return count;
}
char* largestNumber(int* nums, int numsSize) {
    char* ans = NULL;
    int* totalDigits = malloc(sizeof(int));
    *totalDigits = 0;
    if (nums[0] == 0 && nums[1] == 0) {
        int sum = 0;
        for (int i = 0; i < numsSize ; i++){
            sum+=nums[i];
        }
        if (sum == 0) {
            ans = malloc(2);
            ans[0] = '0';
            *totalDigits = 1;
            return ans;
        }       
    }
    int i = 0 , j = 0 , front[numsSize];
    int numberOfdigits[numsSize];
    //bool chosen[numsSize];
    int* f = malloc(sizeof(int));
    for (i = 0; i < numsSize; i++) {
        numberOfdigits[i] = getDigit(nums[i] , f);
        *totalDigits=*totalDigits + numberOfdigits[i];
        front[i] = *f;
        //chosen[i] = false;
        //printf("front: %d, has %d digit \n",front[i],numberOfdigits[i]);
    }
    //use insertion sort
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize-1; j++) {
            if (compare(nums[j],nums[j+1],front[j],front[j+1],numberOfdigits[j],numberOfdigits[j+1])) {
                //printf("enter\n");
                swap(&nums[j],&nums[j+1]);
                swap(&front[j],&front[j+1]);
                swap(&numberOfdigits[j],&numberOfdigits[j+1]);
            } 
        }
    }
    char** stringBuffer = malloc(numsSize*sizeof(char*));
    int s ;
    ans = malloc(*totalDigits);
    ans[0] = '\0';
    for (i = 0; i < numsSize; i++) {
        //printf("%d",nums[i]);
        //printf("numberOfdigits: %d \n", numberOfdigits[i]);
        s = numberOfdigits[i]+1;
        stringBuffer[i] = malloc(s);
        snprintf(stringBuffer[i], s, "%d", nums[i]);
        //printf("%s \n ",stringBuffer[i]);
        strcat(ans,stringBuffer[i]);
        
    }
 //printf("int size is %d s is %d sizeof ans is %d stringbuf is %d nums is %d \n",sizeof(int),s,strlen(ans),strlen(stringBuffer[0]),sizeof(nums[0]));
    //sprintf(ans,"%d",nums);

    return ans;
}
