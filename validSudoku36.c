bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int* rowmap = calloc(10,sizeof(int));
    int* colmap = calloc(10,sizeof(int));
    int* square = calloc(10,sizeof(int));
    int pos , size = 10*sizeof(int);
    int rowstart = 0, colstart = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                pos = board[i][j]-'0';
                rowmap[pos]++;
                if (rowmap[pos] > 1) {
                    return false;
                }
            }
            if (board[j][i] != '.') {
                pos = board[j][i]-'0';
                colmap[pos]++;
                if (colmap[pos] > 1) {
                    return false;
                }
            }
        }
        //check every small square
        for (int a = rowstart; a < rowstart+3; a++) {
            for (int b = colstart; b < colstart+3; b++) {
                if (board[a][b] != '.') {
                    pos = board[a][b]-'0';
                    square[pos]++;
                    if (square[pos] > 1) {
                        return false;
                    }
                }
            }
        }
        colstart+=3;
        if (i>0 && i%3 == 2) {
            rowstart+=3;
            colstart = 0;
        }
        memset(rowmap,0,size);
        memset(colmap,0,size);
        memset(square,0,size);
    }
    return true;
}
