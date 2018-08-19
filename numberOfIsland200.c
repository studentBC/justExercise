void dfs(char** grid, int i, int j , int gridRowSize, int gridColSize) {
    if (i < 0 || j < 0 || i >= gridRowSize || j >= gridColSize || grid[i][j] != '1') return;
    grid[i][j] = '0';
    dfs(grid, i + 1, j, gridRowSize , gridColSize);
    dfs(grid, i - 1, j, gridRowSize , gridColSize);
    dfs(grid, i, j + 1, gridRowSize , gridColSize);
    dfs(grid, i, j - 1, gridRowSize , gridColSize);
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int i , j, count = 0;
    //check for up
    for (i = 0; i < gridRowSize ;i++) {
        for (j = 0; j < gridColSize; j++) {
            if(grid[i][j] == '1') {
                count++;
                dfs(grid,i,j, gridRowSize , gridColSize);
            }
        }
    }
  
    return count;
}
