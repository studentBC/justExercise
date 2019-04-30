class Solution {
public:
    void go (vector<vector<bool>>& beenTo, vector<vector<int>>& original, vector<vector<int>>& grid, int i, int j, int prev, int color) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != prev || beenTo[i][j]) {
            return;
        }
		beenTo[i][j] = true;
        //cout << i << " , " << j << endl;
        if (i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size()-1) {
            if (grid[i][j] != color) grid[i][j] = color;
        } else if (i > 0 && i+1 < grid.size() && j > 0 && j+1 < grid[0].size()) {
            if (original[i-1][j] == prev && original[i+1][j] == prev && original[i][j-1] == prev && original[i][j+1] == prev) {
            } else {
                grid[i][j] = color;
            }  
        } else {
            grid[i][j] = color;
        }
        go (original, grid, i+1,j,prev,color);
        go (original, grid, i,j+1,prev,color);
        go (original, grid, i-1,j,prev,color);
        go (original, grid, i,j-1,prev,color);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if (grid[r0][c0] == color) return grid;
		vector<vector<int>> original = grid;
		vector<vector<bool>> beenTo(grid.size(), vector<bool>(grid[0].size(),false));
        go (beenTo,original,grid,r0,c0,grid[r0][c0], color);
        return grid;
    }
};
//the fatest method
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool visited[50][50];
    int connect[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    void DFS(vector <vector <int>>& grid, int r, int c, int target)
    {
        visited[r][c] = true;
        for(int i = 0; i < 4; i++)
        {
            int next_r = r + connect[i][0], next_c = c + connect[i][1];
            if(next_r != grid.size() && next_r != -1 && next_c != grid[0].size() && next_c != -1 && grid[next_r][next_c] == target && !visited[next_r][next_c])
                DFS(grid, next_r, next_c, target);
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        memset(visited, 0, 50 * 50 * sizeof(bool));
        DFS(grid, r0, c0, grid[r0][c0]);
        for(int r = 0; r < grid.size(); r++)
        {
            for(int c = 0; c < grid[0].size(); c++)
            {
                if(visited[r][c])
                {
                    if(r == 0 || r == grid.size() - 1 || c == 0 || c == grid[0].size() - 1)
                        grid[r][c] = color;
                    for(int i = 0; i < 4; i++)
                    {
                        int next_r = r + connect[i][0], next_c = c + connect[i][1];
                        if(next_r != grid.size() && next_r != -1 && next_c != grid[0].size() && next_c != -1 && !visited[next_r][next_c])
                            grid[r][c] = color;
                    }
                }
            }
        }
        return grid;
    }
};
