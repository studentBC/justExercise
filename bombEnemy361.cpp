/*
Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0', return the maximum enemies you can kill using one bomb. You can only place the bomb in an empty cell.

The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too strong to be destroyed.

 

Example 1:


Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3
Example 2:


Input: grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 'W', 'E', or '0'.
*/

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }

    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0, rowHits = 0, colHits[500];
        memset(colHits, 0, sizeof(colHits));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // check row
                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowHits = 0;
                    for (int k = j; k < n; ++k) {
                        if (grid[i][k] == 'W') break;
                        else if (grid[i][k] == 'E') ++rowHits;
                    }
                }

                // check col
                if (i == 0 || grid[i - 1][j] == 'W') {
                    colHits[j] = 0;
                    for (int k = i; k < m; ++k) {
                        if (grid[k][j] == 'W') break;
                        else if (grid[k][j] == 'E') ++colHits[j];
                    }
                }

                if (grid[i][j] == '0') res = max(res, rowHits + colHits[j]);
            }
        }
        return res;
    }
};
