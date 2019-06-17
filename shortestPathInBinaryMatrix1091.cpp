//using dfs will TLE
class Solution {
public:
    void go (int i, int j, vector<vector<int>>& grid, int length, vector<vector<bool>> beenTo, int& ans) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 1 || beenTo[i][j]) return;
        //cout << i <<" , " << j << endl;
        beenTo[i][j] = true;
        if (i == grid.size()-1 && j == grid[0].size()-1) {
            if (length < ans) ans = length;
        }
        go (i,j+1,grid,length+1,beenTo,ans);
        go (i+1,j+1,grid,length+1,beenTo,ans);
        go (i+1,j,grid,length+1,beenTo,ans);
        go (i+1,j-1,grid,length+1,beenTo,ans);
        go (i,j-1,grid,length+1,beenTo,ans);
        go (i-1,j-1,grid,length+1,beenTo,ans);
        go (i-1,j,grid,length+1,beenTo,ans);
        go (i-1,j+1,grid,length+1,beenTo,ans);
    }
    void Go (int i, int j, vector<vector<int>>& grid, int length, vector<vector<bool>>& beenTo, int& ans) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 1 || beenTo[i][j]) return;
        //cout << i <<" , " << j << endl;
        beenTo[i][j] = true;
        if (i == grid.size()-1 && j == grid[0].size()-1) {
            if (length < ans) ans = length;
        }
        Go (i,j+1,grid,length+1,beenTo,ans);
        Go (i+1,j+1,grid,length+1,beenTo,ans);
        Go (i+1,j,grid,length+1,beenTo,ans);
        Go (i+1,j-1,grid,length+1,beenTo,ans);
        Go (i,j-1,grid,length+1,beenTo,ans);
        Go (i-1,j-1,grid,length+1,beenTo,ans);
        Go (i-1,j,grid,length+1,beenTo,ans);
        Go (i-1,j+1,grid,length+1,beenTo,ans);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        vector<vector<bool>>beenTo(grid.size(),vector<bool>(grid[0].size(), false));
        vector<vector<bool>>beento(grid.size(),vector<bool>(grid[0].size(), false));
        
        Go (0,0,grid,1,beento,ans);
        if (ans == INT_MAX) return -1;
        go (0,0,grid,1,beenTo,ans);
        return ans;
    }
};
//using bfs
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>path;
        path.push({0,0});
        int ans = 0;
        while (!path.empty()) {
            ans++;
            queue<pair<int,int>>temp;
            while (!path.empty()) {
                pair<int,int>p = path.front();
                path.pop(); 
                if (p.first > -1 && p.first < grid.size() && p.second > -1 && p.second < grid.size() && !grid[p.first][p.second]) {
                    grid[p.first][p.second] = 1; 
                    if (p.first+1 == grid.size() && p.second+1 == grid[0].size()) return ans;
                    for (int i = -1; i < 2; ++i) {
                        for (int j = -1; j < 2; ++j) {
                            if (i != 0 || j != 0)temp.push({p.first+i, p.second+j});
                        }  
                    }  
                }
            }
            path = temp; 
        }
        return -1;
    }
};

