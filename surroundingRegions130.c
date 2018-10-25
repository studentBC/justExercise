void go(int i, int j, char** board, int down, int right,bool* connected,bool** beenTo) {
    //printf("0. %d , %d \n",i,j);
    
    if (  board[i][j] == 'X' || beenTo[i][j]) {
        return;
    } else if ((i == down || i == 0 || j == right || j == 0) && board[i][j] == 'O' ) {
        //printf("has entered \n");
        *connected = true;
        return;
    } /*else if (*connected) {
        board[i][j] = 'O';
        return ;
    }*/
    //board[i][j] = 'X';
    beenTo[i][j] = true;
    //printf("been to %d , %d \n",i,j);
    //go up
    go(i-1,j,board,down,right,connected,beenTo);
    //printf("1. %d , %d \n",i,j);
    //go right
    go(i,j+1,board,down,right,connected,beenTo);
    //printf("2. %d , %d \n",i,j);
    //go down
    go(i+1,j,board,down,right,connected,beenTo);
    //printf("3. %d , %d \n",i,j);
    //go left
    go(i,j-1,board,down,right,connected,beenTo);
    //printf("4. %d , %d \n",i,j);
    //board[i][j] = tem;
    //printf("get back %d , %d \n",i,j);
    /*
    if (board[i][j] == 'O') {
        printf("have gone to %d , %d \n",i,j);
        board[i][j] = 'X';
    }
    if (!*connected) {
        printf("***  %d , %d ***\n",i,j);
        board[i][j] = 'X';
        return;
    }
    */
    return;
}
void gochange(int i, int j, char** board, int down, int right,bool** beenTo) {
    //printf("c0. %d , %d \n",i,j);
    
    if (beenTo[i][j] == false || board[i][j] == 'X') {
        return;
    } 
    
    board[i][j] = 'X';
    //printf("change %d , %d \n",i,j);
    //go up
    gochange(i-1,j,board,down,right,beenTo);
    //printf("c1. %d , %d \n",i,j);
    //go right
    gochange(i,j+1,board,down,right,beenTo);
    //printf("c2. %d , %d \n",i,j);
    //go down
    gochange(i+1,j,board,down,right,beenTo);
    //printf("c3. %d , %d \n",i,j);
    //go left
    gochange(i,j-1,board,down,right,beenTo);
    //printf("c4. %d , %d \n",i,j);

    return;
}
void solve(char** board, int boardRowSize, int boardColSize) {
    bool* connected = malloc(sizeof(bool));
    if (boardRowSize == 0 && boardColSize == 0) {
        return NULL;
    }
    bool** beenTo = malloc(sizeof(bool*)*boardRowSize);
    for (int i = 0; i < boardRowSize; i++) {
        beenTo[i] = malloc(sizeof(bool)*boardColSize);
    }
    for (int a = 0; a < boardRowSize; a++) {
        for (int b = 0; b < boardColSize; b++) {
            beenTo[a][b] = false;
        }
    }
    //go(2,3,board,boardRowSize-1,boardColSize-1,connected);
    int row = boardRowSize -1 , col = boardColSize-1;
    //printf("row %d , col %d \n",row,col);
    //go(3,3,board,boardRowSize-1,boardColSize-1,connected,beenTo);
   
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (board[i][j] == 'O' && !beenTo[i][j]) {
                *connected = false;
                //printf("====  found: %d , %d ====\n",i,j);
                go(i,j,board,boardRowSize-1,boardColSize-1,connected,beenTo);
                
                    
                if(!*connected) {
                    gochange(i,j,board,boardRowSize-1,boardColSize-1,beenTo);
                }
                
                //printf("%c \n",board[i][j]);
            }
        }
    }
    return NULL;
}
//the fatest method
void
dfs(char **board, int r, int c, int rows, int cols) {
  board[r][c] = 'S';

  /* 上下左右四个方向上的'O'都改为'S'. */
  if (r > 0 && board[r - 1][c] == 'O')
    dfs(board, r - 1, c, rows, cols);

  if (r < rows - 1 && board[r + 1][c] == 'O')
    dfs(board, r + 1, c, rows, cols);

  if (c > 0 && board[r][c - 1] == 'O')
    dfs(board, r, c - 1, rows, cols);

  if (c < cols - 1 && board[r][c + 1] == 'O')
    dfs(board, r, c + 1, rows, cols);
}

void
solve(char **board, int rows, int cols) {
  int i, j;

  /* 扫描上下两条边. */
  for (i = 0; i < cols; i++) {
    if (board[0][i] == 'O')
      dfs(board, 0, i, rows, cols);

    if (board[rows - 1][i] == 'O')
      dfs(board, rows - 1, i, rows, cols);
  }

  /* 扫描左右两条边. */
  for (i = 0; i < rows; ++i) {
    if (board[i][0] == 'O')
      dfs(board, i, 0, rows, cols);

    if (board[i][cols - 1] == 'O')
      dfs(board, i, cols - 1, rows, cols);
  }

  /* 再次遍历board,将被包围的'O'置为'X',未被包围的'O'恢复为'O'. */
  for (i = 0; i < rows; ++i) {
    for (j = 0; j < cols; ++j)
      if (board[i][j] == 'S')
        board[i][j] = 'O';
      else if (board[i][j] == 'O')
        board[i][j] = 'X';
  }
}
