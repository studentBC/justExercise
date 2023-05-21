class Solution {
public:
    int row, col;
    int direct[5] = {-1, 0, 1, 0, -1};
    void go (int i, int j, bool& invalid, vector<vector<int>>& grid) {
        if ( i < 0 || i >= row || j < 0 || j >= col) return;
        if (grid[i][j] == 1) return;
        if (i == 0 || j == 0 || i+1 == row || j+1 == col) {
            invalid = true;
        }
        grid[i][j] = 1;
        for (int a = 0; a < 4; a++) {
            go (i+direct[a], j+direct[a+1], invalid, grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!grid[i][j]) {
                    bool invalid = false;
                    go (i, j, invalid, grid);
                    if (!invalid) ans++;
                }
            }
        }
        return ans;
    }
};
