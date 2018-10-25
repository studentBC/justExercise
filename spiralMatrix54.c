/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void go(int** matrix, int x, int y, int right, int down, int left, int up, int* ans, int* count) {
    //printf("\( %d , %d \) , right: %d , left: %d, up: %d, down: %d\n",x,y,right,left,up,down);
    //int temp;
    if (matrix[x][y] == INT_MIN) {
        return ;
    }
    ans[*count] = matrix[x][y];
    matrix[x][y]=INT_MIN;
    *count = *count+1;
    
    //go right directly
    if (y < right) {
        if (matrix[x][y+1] != INT_MIN) {
            if (x > up && matrix[x-1][y] != INT_MIN) {
                //printf("still can go up man \n");
            } else {
                //printf("go right \n");
                go(matrix , x, y+1, right, down, left, up, ans, count);
            }
        }
    } 
    //go down
    if (x < down) {
        if (matrix[x+1][y] != INT_MIN) {
            //printf("go down\n");
            go(matrix , x+1, y, right, down , left, up, ans, count);
        }     
    }
    //go left
    if (y > left) {
        if (matrix[x][y-1] != INT_MIN) {
            //printf("go left \n");
            go(matrix , x, y-1, right, down , left, up, ans, count);
        }
        
    }
    //go up
    if (x > up) {
        if (matrix[x-1][y] != INT_MIN) {
            //printf("go up \n");
            go(matrix , x-1, y, right, down , left, up, ans, count);
            
        }
    }
    //printf("%d -> ",ans[*count-1]);
    return;
}

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int total = matrixRowSize*matrixColSize;
    int* ans = malloc(sizeof(int)*total),* count = malloc(sizeof(int));
    *count = 0;
    go(matrix,0,0,matrixColSize-1, matrixRowSize-1 ,0,0, ans,count);
    return ans;

}
