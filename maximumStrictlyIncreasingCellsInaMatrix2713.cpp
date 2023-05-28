/*
Intuition
Apply dp solution,
dp[i][j] means the maximum steps can go from the first cell.
Initial all dp[i][j] = 0 at first,
and the smallest cell A[i][j] will start with dp[i][j] = 1.


Explanation
Sort pairs [i, j] by value of M[i][j],
and then iterate cells in increasing order.

For each M[i][j],
find out the current maximum steps in the same row and col,
dp[i][j] = max(max steps in row, max steps in col) + 1.

To make this process efficient,
we use res[i] to record the maximum step for row i,
we use res[m + j] to record the maximum step for col j.

Repeat this process until we find the steps for all cells,
return the maximum one.
*/

    int maxIncreasingCells(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        map<int, vector<int>> A;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                A[M[i][j]].push_back(i * n + j);
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> res(n + m, 0);
        for (auto& [a, pos] : A) {
            for (int p : pos) {
                int i = p / n, j = p % n;
                dp[i][j] = max(res[i], res[m + j]) + 1;
            }
            for (int p : pos) {
                int i = p / n, j = p % n;
                res[m + j] = max(res[m + j], dp[i][j]);
                res[i] = max(res[i], dp[i][j]);
            }
        }
        return *max_element(res.begin(), res.end());
    }
