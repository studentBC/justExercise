/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical). You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island has the same shape as another island (and not rotated or reflected).

Notice that:

11
1
and

 1
11
are considered different island, because we do not consider reflection / rotation.

Input:
  [
    [1,1,0,0,0],
    [1,1,0,0,0],
    [0,0,0,1,1],
    [0,0,0,1,1]
  ]
Output: 1
*/
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    int step[5] = {1,0,-1,0,1};
    int row, col;
	unordered_set<string>path;
    void go (int i, int j, int pi, int pj, vector<vector<int>> &grid, string& p) {
        //cout <<i <<" , " << j << endl;
        if (i >= row || i < 0 || j >= col || j < 0 || !grid[i][j]) return;
        grid[i][j] = 0;
		p+=(to_string(i-pi)+","+to_string(j-pj));
        for (int a = 0; a < 4; a++) {
            go (i+step[a], j+step[a+1], i, j, grid, p);
        }   
    }
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        int ans = 0;
        row = grid.size();
        if (row == 0) return 0;
        col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) {
					string temp;
                    go (i, j, i, j, grid, temp);
                    if (path.find(temp)==path.end()) {
						path.insert(temp);
						ans++;
					}
                }
            }
        }
        return ans;
    }
};

