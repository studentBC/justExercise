/*
 * Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note: You can only put the bomb at an empty cell.

Example:

Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3
Explanation: For the given grid,

0 E 0 0
E 0 W E
0 E 0 0

Placing a bomb at (1,1) kills 3 enemies.

worng case due to bomb can only be placed at '0'
[["W"],["E"],["W"],["0"],["E"]]
[["E"]]
 */
class Solution {
public:
    int get (int i, int j, vector<vector<char>>& grid) {
        int count = 0;
        for (int a = j; a < grid[i].size(); a++) {
            if (grid[i][a] == 'E') {
                count++;
            } else if (grid[i][a] == 'W') break;
        }
        for (int a = j-1; a > -1; a--) {
            if (grid[i][a] == 'E') {
                count++;
            } else if (grid[i][a] == 'W') break;
        }
        for (int a = i-1; a > -1; a--) {
            if (grid[a][j] == 'E') {
                count++;
            } else if (grid[a][j] == 'W') break;
        }
        for (int a = i+1; a < grid.size(); a++) {
            if (grid[a][j] == 'E') {
                count++;
            } else if (grid[a][j] == 'W') break;
        }
        return count;
    }
    int maxKilledEnemies(vector<vector<char>>& grid) {
        //vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(),0));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '0')ans = max(ans, get(i,j,grid));
            }
        }
        return ans;
    }
};
//8ms solution
auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxKilledEnemies(const vector<vector<char>>& grid) {
        const int m = grid.size();
        if(m == 0)
        {
            return 0;
        }
        
        const int n = m ? grid[0].size() : 0;
        int rowhits = 0;
        int maxhits = 0;
        vector<int> colhits (n, 0);
        
        for(int i = 0; i < m ; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(j == 0 || grid[i][j-1] == 'W')
                {
                    rowhits = 0;
                    for(int  k = j; k < n && grid[i][k] != 'W'; ++k)
                    {
                        rowhits += (grid[i][k] == 'E');
                    }
                }
                
                if( i == 0 || grid[i-1][j] == 'W')
                {
                    colhits[j] = 0;
                    for(int k = i; k < m && grid[k][j] != 'W'; ++k)
                    {
                        colhits[j] += (grid[k][j] == 'E');
                    }
                }
                
                if(grid[i][j] == '0')
                {
                    maxhits = max(maxhits, rowhits + colhits[j]);
                }
            }
        }
        
        return maxhits;
    }
};
