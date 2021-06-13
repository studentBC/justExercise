class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
		int r = grid.size(), c = grid[0].size(), ans = 0;
		vector<vector<int>>row(r+2, vector<int>(c+2)), col(row), right(row), left(row);
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				row[i][j]+=grid[i-1][j-1] + row[i][j-1];
				col[i][j]+=grid[i-1][j-1]+col[i-1][j];
				right[i][j]+=grid[i-1][j-1]+right[i-1][j-1];
				left[i][j]+=grid[i-1][j-1]+left[i-1][j+1];
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				for (int k = min(r-i, c-j); k > ans; k--) {
					int sum = right[i+k][j+k]-right[i-1][j-1];
					bool valid = sum == left[i+k][j] - left[i-1][j+k+1];
					for (int l = 0; valid && l <= k; l++) {
						valid &= sum == row[i+l][j+k] - row[i+l][j-1];
						valid &= sum == col[i+k][j+l] - col[i-1][j+l];
					}
					ans = valid ? k : ans;
				}
			}
		}
		return ans+1;
    }
};

