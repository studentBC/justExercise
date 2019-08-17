/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
Example:

Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 7 

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total 
             travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int pace[] = {0,1,0,-1,0};
        int walk = 0, ans = -1, x, y;
        auto total = grid;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    queue<pair<int,int>>pos;
                    pos.emplace(i,j);
                    ans = -1; 
                    auto dis = grid;
                    while (!pos.empty()) {
                        auto ij = pos.front();
                        pos.pop();
                        for (int k = 0; k < 4; k++) {
                            x = ij.first+pace[k];
                            y = ij.second+pace[k+1];
                            if (x < grid.size() && x > -1 && y < grid[0].size() && y > -1 && grid[x][y] == walk) {
                                grid[x][y]--;
                                dis[x][y]=dis[ij.first][ij.second]+1;
                                total[x][y] += dis[x][y]-1;
                                pos.emplace(x,y);
                                if (ans < 0 || ans > total[x][y]) {
                                    ans = total[x][y];
                                }   
                            }   
                        }   
                    }   
                    walk--;
                }   
            }   
        } 
        return ans;
    }
};
//the concept solution
class Solution {
public:
int shortestDistance(vector<vector<int>> grid) {
    int m = grid.size(), n = grid[0].size();
    auto total = grid;
    int walk = 0, mindist, delta[] = {0, 1, 0, -1, 0};
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (grid[i][j] == 1) {
                mindist = -1;
                auto dist = grid;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (q.size()) {
                    auto ij = q.front();
                    q.pop();
                    for (int d=0; d<4; ++d) {
                        int i = ij.first + delta[d];
                        int j = ij.second + delta[d+1];
                        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk) {
                            grid[i][j]--;
                            dist[i][j] = dist[ij.first][ij.second] + 1;
                            total[i][j] += dist[i][j] - 1;
                            q.emplace(i, j);
                            if (mindist < 0 || mindist > total[i][j])
                                mindist = total[i][j];
                        }
                    }
                }
                walk--;
            }
        }
    }
    return mindist;
}
};
//the fatest method
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        if(rows==0)
            return 0;
        int numBuil = 0;
        int cols = grid[0].size();
        
        vector<vector<int>> hits(rows, vector<int>(cols,0));
        vector<vector<int>> dist(rows, vector<int>(cols,0));
        
        for(int i=0;i<rows;i+=1)
            for(int j=0;j<cols;j+=1)
                if(grid[i][j]==1)
                   numBuil+=1;
        
        for(int i=0;i<rows;i+=1)
            for(int j=0;j<cols;j+=1)
                if(grid[i][j]==1)
                    if(!helper(grid, numBuil, hits, dist,i,j))
                        return -1;
        
        int ans = INT_MAX;
        for(int i=0;i<rows;i+=1)
            for(int j=0;j<cols;j+=1)
                if(grid[i][j]==0 && hits[i][j] == numBuil && ans>dist[i][j])
                    ans = dist[i][j];
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
        
    }
    
    bool helper(vector<vector<int>>& grid, int builds, vector<vector<int>> &hits, vector<vector<int>> &dist,int row, int       col)
    {
        queue<pair<int,int>> q;
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        q.push({row,col});
        int nodes = 0;
        int dis = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        while(!q.empty())
        {
            int size = q.size();
            dis+=1;
            for(int i=0;i<size;i+=1)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(auto it:dirs)
                {
                    int r = x + it.first;
                    int c = y + it.second;
                    
                    if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==2 || visited[r][c] == true)
                        continue;
                    
                    visited[r][c] = true;
                    
                    if(grid[r][c] == 1)
                        nodes+=1;
                    
                    else
                    {
                        q.push({r,c});
                        hits[r][c]+=1;
                        dist[r][c] += dis;
                    }
                }
            }
        }
        
        return nodes ==  builds;
    }
};
