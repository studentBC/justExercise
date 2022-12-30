class Solution {
public:
    int limit, ans = 0;
    vector<int>dp;
    bool check(int n) {
        int end = sqrt(n);
        return end*end == n;
    }
    int go (int n, int count) {
        if (dp[n] != INT_MAX) return dp[n];
        if (check(n)) {
            return 1;
        }
        int square;
        for (int i = limit; i > 0 ; i--) {
            square = i*i;
            if (n>=square) dp[n] = min(dp[n], go (n-i*i, count+1)+1);
        }
        return dp[n];
    }
    int numSquares(int n) {
        limit = sqrt(n);
        ans = n;
        dp = vector<int>(n+1, INT_MAX);
        dp[0] = 1;
        return go (n, 0);
        return ans;
    }
};
