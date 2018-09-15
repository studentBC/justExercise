void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    
    int i , j , k;
    bool map[matrixRowSize][matrixColSize];
    for (i = 0; i < matrixRowSize ; i++) {
        //zrow[i] = -1;
        for (j = 0; j < matrixColSize ;j++) {
            
                map[i][j] = false;
            
        }
     }
    for (i = 0; i < matrixRowSize ; i++) {
        //zrow[i] = -1;
        for (j = 0; j < matrixColSize ;j++) {
            //zcol[j] = -1;
            if (matrix[i][j] == 0) {
                //go right
                for (k = j+1; k < matrixColSize ; k++) {
                    //printf("%d , %d \n",i,k);
                    map[i][k] = true;
                }
                //go left
                for (k = j-1; k > -1 ; k--) {
                    //printf("%d , %d \n",i,k);
                    map[i][k] = true;
                }
                //go up
                for (k = i-1;k > -1 ;k--) {
                    //printf("%d , %d \n",i,k);
                    map[k][j] = true;
                }
                //go down
                for (k = i+1;k < matrixRowSize ;k++) {
                    //printf("%d , %d \n",i,k);
                    map[k][j] = true;
                }
            }
        }
    }
     for (i = 0; i < matrixRowSize ; i++) {
        //zrow[i] = -1;
        for (j = 0; j < matrixColSize ;j++) {
            if (map[i][j]) {
                matrix[i][j] = 0;
            }
        }
     }
    return ;
}
