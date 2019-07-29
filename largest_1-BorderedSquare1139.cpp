class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        vector<vector<int>>row(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>>col(grid.size(),vector<int>(grid[0].size(),0));
		int ans = 0, length;
        for (int i = 0; i < grid.size(); i++) {
        	for (int j = 0; j < grid[i].size(); j++) {
                if (j == 0) {
                    if (grid[i][j]) {
						row[i][j] = 1;
						ans = 1;
					}
                } else {
                    if (!grid[i][j]) {
                        row[i][j] = 0;
                    } else {
                        row[i][j] = row[i][j-1]+1;
						ans = 1;
                    }
                }
			}
        }
		for (int i = 0; i < grid[0].size(); i++) {
        	for (int j = 0; j < grid.size(); j++) {
                if (j == 0) {
                    if (grid[j][i]) col[j][i] = 1;
                } else {
                    if (!grid[j][i]) {
                        col[j][i] = 0;
                    } else {
                        col[j][i] = col[j-1][i]+1;
                    }
                }
			}
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                length = min(grid.size()-i, grid[0].size()-j);
				for (int k = 1; k < length; k++) {
					if (grid[i][j] && (row[i][j+k] - row[i][j]) == (row[i+k][j+k]-row[i+k][j]) && 
							(col[i+k][j]-col[i][j]) == (col[i+k][j+k]-col[i][j+k]) && 
							row[i][j+k] - row[i][j]>= k && col[i+k][j]-col[i][j] >= k) ans = max(ans, (k+1)*(k+1));
				}
            }
        }
		return ans;
    }
};
