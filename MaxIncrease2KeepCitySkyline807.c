class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>col , row;
        int mc = -1, ml = -1, sum = 0, min;
        for (int i = 0; i < grid.size(); i++) {
            mc = -1; ml = -1;
            for (int j = 0; j < grid[i].size(); j++) {
                if  (mc < grid[i][j]) {
                    mc = grid[i][j];
                }
                if (ml < grid[j][i]) {
                    ml = grid[j][i];
                }
            }
            col.push_back(mc);
            row.push_back(ml);
        }
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
            	min = (col[i] < row[j])?col[i]:row[j];
            	sum+=(min-grid[i][j]);
			}
		}
        return sum;
    }
};
//the fatest method
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        vector<int> row(grid.size(), 0);
        vector<int> col(grid[0].size(), 0);
        for(int i = 0; i < grid.size(); i++) {
            int maxR = 0;
            for(int j = 0; j < grid[0].size(); j++) {
                maxR = max(maxR, grid[i][j]);
            }
            row[i] = maxR;
        }
        for(int j = 0; j < grid[0].size(); j++) {
            int maxR = 0;
            for(int i = 0; i < grid.size(); i++) {
                maxR = max(maxR, grid[i][j]);
            }
            col[j] = maxR;
        }
        int result = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j =0; j < grid[0].size(); j++) {
                int m = min(row[i], col[j]);
                result += (- grid[i][j] + m);
            }
        }
        return result;
    }
};
