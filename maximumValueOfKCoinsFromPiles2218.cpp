class Solution {
public:
    int go (int i, int k, int& len, vector<vector<int>>& piles, vector<vector<int>>& dp) {
            if (i == len || k == 0) return 0;
            else if (dp[i][k]) return dp[i][k];
            int res = go(i+1, k, len, piles, dp), cur = 0;
            for (int j = 0; j < piles[i].size() && j < k; j++) {
                    cur+=piles[i][j];
                    res = max(res, go(i+1, k-j-1, len, piles, dp)+cur);
            }
            return dp[i][k] = res;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int len = piles.size();
        vector<vector<int>>dp(len+1, vector<int>(k+1, 0));
        return go(0, k, len, piles, dp);
    }
};

class Solution {
public:
    int f[3][2010];
    int maxValueOfCoins(vector<vector<int>>& a, int k) {
        memset(f, 0, sizeof(f));
        int curMax = 0;
        int cur = 0;
        int next = 1;
        for (int i = 0; i < a.size(); i++) {
            int curTop = 0;
            for (int j = 0; j < a[i].size(); j++) {
                curTop += a[i][j];
                for (int p = curMax; p >= 0; p--) {
                    f[next][p + j+1] = max(f[next][p+j+1], f[cur][p] + curTop);
                }
            }
            curMax += a[i].size();
            for (int p = 0; p <= curMax; p++) {
                f[cur][p] = f[next][p];
            }
        }
        return f[cur][k];
    }
};
