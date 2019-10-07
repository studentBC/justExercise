class Solution {
public:
    
    void go (int i, int j, int sum, int& gold, vector<vector<int>> grid) {
        int step[]={0,1,0,-1,0};
        if (grid[i][j] == 0) return;
        gold = max(gold, sum);
        grid[i][j] = 0;
        for (int a = 0; a < 4; a++) {
            int x = i+step[a];
            int y = j+step[a+1];
            if (x< grid.size() && x > -1 && y > -1 && y < grid[0].size() && grid[x][y]) {
                go (x, y, sum+grid[x][y], gold, grid);
            }
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>>pos;
        int step[]={0,1,0,-1,0};
        int x, y, xp, yp, ans = 0, gold;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    gold = grid[i][j];
                    go (i,j,gold, gold, grid);
                    ans = max(gold,ans);
                }
            }
        }
        return ans;
    }
};
//40 ms solution
class Solution {
    vector<vector<int>> grid;
    int g = 0;
    int gmax = 0;
    void backtrack(int i, int j) {
        int x = grid[i][j];
        grid[i][j] = 0;
        g+=x;
        gmax = max(gmax,g);
        
        if (i>0 && grid[i-1][j]) backtrack(i-1,j);
        if (j>0 && grid[i][j-1]) backtrack(i,j-1);
        if (i<grid.size()-1 && grid[i+1][j]) backtrack(i+1,j);
        if (j<grid[0].size()-1 && grid[i][j+1]) backtrack(i,j+1);
        
        g-=x;
        grid[i][j] = x;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        this->grid = grid;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]) backtrack(i,j);
            }
        }
        return gmax;
    }
};
