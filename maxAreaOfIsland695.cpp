class Solution {
public:
    void go (int i , int j , int& count, vector<vector<int>>& grid) {
        if (i  < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)return;
        count++;
        grid[i][j] = 0;
        go (i+1,j,count,grid);
        go (i,j+1,count,grid);
        go (i-1,j,count,grid);
        go (i,j-1,count,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0 , count;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                count = 0;
                if (grid[i][j] > 0) {
                    go (i,j,count,grid);
                    if (count > ans) {
                        ans = count;
                    }
                }
            }
        }
        return ans;
    }
};
