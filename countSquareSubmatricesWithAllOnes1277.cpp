class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(),col = matrix[0].size(), sum = 0, ans = 0, len;
        vector<vector<int>>dp(row, vector<int>(col, 0));
        for (int j = 0; j < col; j++) {
            if (matrix[0][j]) {
                sum++;
                ans++;
            }
            dp[0][j] = sum;
        }
        sum = 0;
        for (int j = 0; j < row; j++) {
            if (matrix[j][0]) {
                sum++;
                ans++;
            }
            dp[j][0] = sum;
        }
        
        if (matrix[0][0]) ans--;
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j]) {
                    ans++;
                    dp[i][j]++;
                }
                dp[i][j] = dp[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        /*cout << ans<<endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << dp[i][j]<<", ";
            }
            cout << endl;
        }*/
        len = min(row, col);
        int area = 0;
        for (int l = 2; l <= len; l++) {
            area = l*l;
            for (int i = l-1; i < row; i++) {
                for (int j = l-1; j < col; j++) {
                    sum = dp[i][j];
                    if (i-l > -1) sum-=dp[i-l][j];
                    if (j-l > -1) sum-=dp[i][j-l];
                    if (i-l > -1 && j-l > -1) sum+=dp[i-l][j-l];
                    
                    if (sum == area) ans++;
                }
            }
        }
        return ans;
    }
};
