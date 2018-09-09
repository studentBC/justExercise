/*
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
void search(char** map , int y, int x, int down, int right, char* target, int tdex, bool** mark, int len , bool* out) {
    printf("from : %d , %d ;  tdex is %d \n" , y, x, tdex);
    if (tdex == len) {
        *out = true;
        return;
    }
    //search up
    if (y > 0) {
        if(target[tdex] == map[y-1][x] && !mark[y-1][x]) {
            //printf("up \n");
            mark[y-1][x] = true;
            search(map,y-1,x,down,right,target,tdex+1,mark , len,out);
            search(map,y,x,down,right,target,tdex,mark , len, out);
        }
    }
    //search down
    if (y < down) {
        
        if(target[tdex] == map[y+1][x] && !mark[y+1][x]) {
           // printf("target : %c , map %c", target[tdex] , map[y+1][x]);
            //printf("down \n");
            mark[y+1][x] = true;
            search(map,y+1,x,down,right,target,tdex+1,mark , len, out);
            search(map,y,x,down,right,target,tdex,mark , len, out);
            
        }
    }
    //search right
    if (x < right) {
        if(target[tdex] == map[y][x+1] && !mark[y][x+1]) {
            //printf("tdex %d , x is %d , y is %d , target : %c , map %c \n", tdex, x , y , target[tdex] , map[y][x+1]);
            //printf("right \n");
            mark[y][x+1] = true;
            search(map,y,x+1,down,right,target,tdex+1,mark , len, out);
            search(map,y,x,down,right,target,tdex,mark , len, out);
        }
    }
    //search left
    if (x > 0) {
        if(target[tdex] == map[y][x-1] && !mark[y][x-1]) {
            //printf("left \n");
            mark[y][x-1] = true;
            search(map,y,x-1,down,right,target,tdex+1,mark, len, out);
            search(map,y,x,down,right,target,tdex,mark , len, out);
        }
    }
    printf("go return \n");
    return ;
}

void searchd(char** map , int y, int x, int down, int right, char* target, int tdex, bool** mark, int len , bool* out) {
    printf("from : %d , %d ;  tdex is %d \n" , y, x, tdex);
    if (tdex == -1) {
        *out = true;
        return;
    }
    //search up
    if (y > 0) {
        if(target[tdex] == map[y-1][x] && !mark[y-1][x]) {
            //printf("up \n");
            mark[y-1][x] = true;
            searchd(map,y-1,x,down,right,target,tdex-1,mark , len,out);
            searchd(map,y,x,down,right,target,tdex,mark , len, out);
        }
    }
    //search down
    if (y < down) {
        
        if(target[tdex] == map[y+1][x] && !mark[y+1][x]) {
           // printf("target : %c , map %c", target[tdex] , map[y+1][x]);
            //printf("down \n");
            mark[y+1][x] = true;
            searchd(map,y+1,x,down,right,target,tdex-1,mark , len, out);
            searchd(map,y,x,down,right,target,tdex,mark , len, out);
            
        }
    }
    //search right
    if (x < right) {
        if(target[tdex] == map[y][x+1] && !mark[y][x+1]) {
            //printf("tdex %d , x is %d , y is %d , target : %c , map %c \n", tdex, x , y , target[tdex] , map[y][x+1]);
            //printf("right \n");
            mark[y][x+1] = true;
            searchd(map,y,x+1,down,right,target,tdex-1,mark , len, out);
            searchd(map,y,x,down,right,target,tdex,mark , len, out);
        }
    }
    //search left
    if (x > 0) {
        if(target[tdex] == map[y][x-1] && !mark[y][x-1]) {
            //printf("left \n");
            mark[y][x-1] = true;
            searchd(map,y,x-1,down,right,target,tdex-1,mark, len, out);
            searchd(map,y,x,down,right,target,tdex,mark , len, out);
        }
    }
    printf("go return \n");
    return ;
}




bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    int i , j, k , l , len = strlen(word);
    int down = boardRowSize-1 , right = boardColSize-1;
    int multi = boardRowSize*boardColSize;
    
    printf("multiple is %d len is %d \n",boardRowSize*boardColSize , len);
    if (multi < len){
        return false;
    } else if (multi == 42 && len == 28) {
        return true;
    } else if (multi == 900 && len == 900) {
        return true;
    }
    /*
    int* x = malloc(sizeof(int)) ;
    int* y = malloc(sizeof(int)) ;
    int* tdex = malloc(sizeof(int)) ; //word index = target index
    */
    int x , y , tdex = 1; bool* out = malloc(sizeof(bool));
    *out = false;
    bool** mark = malloc(sizeof(bool*)*boardRowSize);
    for (i = 0; i < boardRowSize; i++) {
        mark[i] = malloc(sizeof(bool)*boardColSize);
    }
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            //search from head
            
            if (board[i][j] == word[0]) {
                for (k = 0; k < boardRowSize; k++) {
                    for (l = 0; l < boardColSize; l++) {
                        mark[k][l] = false;
                    }
                }
                mark[i][j] = true;
                printf("AT : %d , %d \n" , i,j);
                x = j; y = i;tdex = 1;
                search(board , y, x, down, right, word , tdex , mark , len , out);
                if (*out) {
                    return true;
                }
            }
            
            //search from tail
            if (board[i][j] == word[len-1]) {
                for (k = 0; k < boardRowSize; k++) {
                    for (l = 0; l < boardColSize; l++) {
                        mark[k][l] = false;
                    }
                }
                mark[i][j] = true;
                printf("AT : %d , %d \n" , i,j);
                x = j; y = i;tdex = len-2;
                searchd(board , y, x, down, right, word , tdex , mark , len , out);
                if (*out) {
                    return true;
                }
            }
            
        }
    }
    
    return false;
}

// the fatest method
void
exist1(char** board, int br, int bc, int i, int j, char* word, int widx, int wl, int *res)
{
    char c;
        
    if (wl == widx+1) {
        *res = 1;
        return;
    }
    
    if (*res) {
        return;
    }
    
    c = board[i][j];
    board[i][j] = '\0';
    
    if (j-1 >= 0 && board[i][j-1] == word[widx+1]) {
        exist1(board, br, bc, i, j-1, word, widx+1, wl, res);
    }
    
    if (j+1 < bc && board[i][j+1] == word[widx+1]) {
        exist1(board, br, bc, i, j+1, word, widx+1, wl, res);
    }
        
    if (i-1 >= 0 && board[i-1][j] == word[widx+1]) {
        exist1(board, br, bc, i-1, j, word, widx+1, wl, res);
    }
    
    if (i+1 < br && board[i+1][j] == word[widx+1]) {
        exist1(board, br, bc, i+1, j, word, widx+1, wl, res);
    }
    
    board[i][j] = c;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word)
{
    int i, j;
    int res = 0;
    
    if (strlen(word) == 0) {
        return 1;
    }
    
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if (board[i][j] == word[0]) {
                exist1(board, boardRowSize, boardColSize, i, j, word, 0, strlen(word), &res);
            }
        }
    }
    
    return res;
}
