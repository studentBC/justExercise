/*
 * Given an m x n binary matrix mat, return the length of the longest line of consecutive one in the matrix.

The line could be horizontal, vertical, diagonal, or anti-diagonal.
 */
class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), ans = 0;
        //row, col, diag, anti-diag
        vector<vector<vector<int>>>dp(row, vector<vector<int>>(col, vector<int>(4, 0)));
        //int dp[10000][10000][4] = {{{ 0 }}};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j]) {
                    // cout << i<<", " << j << endl;
                    if (i && j) dp[i][j][2]=dp[i-1][j-1][2]+1; 
                    else dp[i][j][2] = 1;
                    if (i) dp[i][j][0]=dp[i-1][j][0]+1;  
                    else dp[i][j][0] = 1;
                    if (j) dp[i][j][1]=dp[i][j-1][1]+1;
                    else dp[i][j][1] = 1;
                    if (i && j+1 < col) dp[i][j][3]=dp[i-1][j+1][3]+1;
                    else dp[i][j][3] = 1;
                    ans = max(dp[i][j][0], max(dp[i][j][1], ans));
                    ans = max(dp[i][j][2], max(dp[i][j][3], ans));
                }
            }
        }
        return ans;
    }
};
