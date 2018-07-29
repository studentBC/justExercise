/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    int i = 0;
    //returnSize = (int*)malloc(sizeof(int));
    char** ans = (char**)malloc(sizeof(char*)*n);
    //char f[5] = "Fizz";
    //char b[5] = "Buzz";
    int length = 0;
    int temp = 0;
    for (i = 1; i<=n; i++) {
        ans[i-1] = (char*)malloc(sizeof(char)*9);
        if(i%3 == 0 && i%5!=0) {
            ans[i-1] = "Fizz";
            //length = 4;
        }else if (i%5 == 0 && i%3!=0) {
            ans[i-1] ="Buzz";
            //length+=4;
        } else if (i%5 == 0 && i%3==0) {
            ans[i-1] ="FizzBuzz";
            //length+=4;
        }else {
            temp = i;
            sprintf(ans[i-1], "%d", i);
            /*
            length =1;           
            while(temp>10){
                temp/=10;
                length++;
            }
            */
        }
        //printf("%s  \n",ans[i-1]);
    }
    *returnSize = n;
    return ans;
}
