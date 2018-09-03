/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    int map[strsSize][strsSize+2];int total = 0 , stringlength;
    for (int i = 0; i < strsSize; i++) {
        total = 0;
        stringlength = strlen(strs[i]);
        for (int j = 0; j < stringlength; j++) {
            total+=(strs[i][j]-'a');
        }
        printf("total is %d \n",total);
        map[i][0] = total;
        map[i][1] = stringlength;
        map[i][2] = 1;
        map[i][3] = i;
    }
    //start making map for 0 = group key , 1 = string length , 2 = same group count , and next is same group key's index
    int differentNumber = 0, count  , index = 3;
    for (int i = 0; i < strsSize; i++) {
        
        if (map[i][0] > 0) {
            differentNumber++;
            for (int j = i+1;j < strsSize ; j++){
                if ( map[i][0] == map[j][0]) {
                    map[i][index] = j;
                    index++;
                    map[i][2]++;
                    map[j][0] = -1;
                }
            }
        }
    }
    *returnSize = differentNumber;
    printf("different number is %d\n",differentNumber);
    //columnSizes = malloc(sizeof(int*)*differentNumber);
    columnSizes[0] = malloc(sizeof(int)*differentNumber);
    char*** ans = malloc(sizeof(char**)*differentNumber);
    count = 0;
    for (int i = 0; i < strsSize; i++) {
        if (map[i][0] > 0) {
            printf("# %d : key is %d it has %d  members\n",i,map[i][0],map[i][2]);
            ans[count] = malloc(sizeof(char*)*map[i][2]);
            //columnSizes[count] = malloc(sizeof(int));
            columnSizes[0][count] = map[i][2];
                for (int j = 0; j < map[i][2]; j++) {
                    ans[count][j] = calloc((map[i][1]+1) , sizeof(char));
                    for (int k = 0; k < map[i][1]; k++) {
                        printf("%c",strs[map[i][j+3]][k]);
                        ans[count][j][k] = strs[map[i][j+3]][k];
                    }
                    printf("\n");
                }
            count++;
        }
        
    }
    return ans;
}
