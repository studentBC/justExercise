void go(int i, int j, char** board, int down, int right,bool* connected) {
    //printf("0. %d , %d \n",i,j);
    int tem = board[i][j];
    if (  board[i][j] == 'X') {
        return;
    } else if ((i == down || i == 0 || j == right || j == 0) && board[i][j] == 'O' ) {
        *connected = true;
        //printf("enter %d , %d \n",i,j);
        return;
    } else if (*connected) {
        return ;
    }
    board[i][j] = 'X';
    //go up
    go(i-1,j,board,down,right,connected);
    //printf("1. %d , %d \n",i,j);
    //go right
    go(i,j+1,board,down,right,connected);
    //printf("2. %d , %d \n",i,j);
    //go down
    go(i+1,j,board,down,right,connected);
    //printf("3. %d , %d \n",i,j);
    //go left
    go(i,j-1,board,down,right,connected);
    //printf("4. %d , %d \n",i,j);
    board[i][j] = tem;
    //printf("get back %d , %d \n",i,j);
    /*
    if (*connected) {
        //printf("***  %d , %d ***\n",i,j);
        //board[i][j] = 'O';
        return;
    }*/
    
    return;
}
void solve(char** board, int boardRowSize, int boardColSize) {
    bool* connected = malloc(sizeof(bool));
    if (boardRowSize == 0 && boardColSize == 0) {
        return NULL;
    }
    //go(2,3,board,boardRowSize-1,boardColSize-1,connected);
    int row = boardRowSize -1 , col = boardColSize-1;
    printf("row %d , col %d \n",row,col);
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (board[i][j] == 'O') {
                *connected = false;
                //printf("====  found: %d , %d ====\n",i,j);
                go(i,j,board,boardRowSize-1,boardColSize-1,connected);
                if(!*connected) {
                    board[i][j] = 'X';
                }
                //printf("%c \n",board[i][j]);
            }
        }
    }
    
    return NULL;
}
