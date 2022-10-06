class Solution {
public:
    int mod = 1e9+7;
    int go (int& row, int& col, int k, int i, int j, vector<vector<vector<int>>>& dp, vector<vector<int>>& sum) {
        if (sum[i][j] == 0) return 0;
        if (k == 0) return 1;
        if (dp[k][i][j] > -1) return dp[k][i][j];
        int ans = 0;
        for (int r = i+1; r < row; r++) {
            if (sum[i][j]-sum[r][j]) {
                ans+=go(row, col, k-1, r, j, dp, sum)%mod;
                ans%=mod;
            }
        }
        for (int c = j+1; c < col; c++) {
            if (sum[i][j]-sum[i][c]) {
                ans+=go(row, col, k-1, i, c, dp, sum)%mod;
                ans%=mod;
            }
        }
        return dp[k][i][j] = ans;
    }
    int ways(vector<string>& pizza, int k) {
        int len = pizza.size(), width = pizza[0].size();
        vector<vector<vector<int>>>dp(k, vector<vector<int>>(len, vector<int>(width, -1)));
        vector<vector<int>>sum(len+1,  vector<int>(width+1, 0));
        //Note that after each cut the remaining piece of pizza always has the lower right coordinate at (rows-1,cols-1).
        for (int i = len-1; i > -1; i--) {
            for (int j = width-1; j > -1; j--) {
                sum[i][j] = sum[i][j+1]+sum[i+1][j]-sum[i+1][j+1]+ ((pizza[i][j] == 'A')?1:0);
            }
        }
        return go (len, width, k-1, 0, 0, dp, sum);
    }
};
