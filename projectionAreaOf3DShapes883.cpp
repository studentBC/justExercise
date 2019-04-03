class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
 		int xy = 0, yz = 0, zx = 0, rowmax = -1, colmax = -1;
		for (int i = 0; i < grid.size(); i++) {
			rowmax = -1;
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] > 0) xy++;
				if (rowmax < grid[i][j]) rowmax = grid[i][j];
			}
			yz+=rowmax;
		}
		for (int i = 0; i < grid[0].size(); i++) {
			colmax = -1;
			for (int j = 0; j < grid.size(); j++) {
				if (grid[j][i] > colmax) colmax = grid[j][i];
			}
			zx+=colmax;
		}
		return xy+yz+zx;
    }
};
//the fatest method
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0, n = grid.size();
        for (int i = 0, v = 0; i < n; ++i, res += v, v = 0)
            for (int j = 0; j < n; ++j)
                v = max(v, grid[i][j]);
        for (int j = 0, v = 0; j < n; ++j, res += v, v = 0)
            for (int i = 0; i < n; ++i)
                v = max(v, grid[i][j]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) res++;
        return res;
    }
};
