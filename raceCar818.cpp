//https://www.youtube.com/watch?v=HzlEkUt2TYs&ab_channel=HuaHua
class Solution {
public:
    int go (int pos, vector<int>& dp) {
        if (dp[pos]) return dp[pos];
        int n = ceil(log2(pos+1)), cur;
        if (1 << n == pos+1) return dp[pos] = n;

        dp[pos] = n+1+go((1 << n) -1 - pos, dp);
        for (int i = 0; i < n-1; i++) {
            cur = (1<<(n-1)) - (1<<i);
            dp[pos] = min(dp[pos], n+i+1+go(pos-cur, dp));
        }
        return dp[pos];
    }
    int racecar(int target) {
        vector<int>dp(target+1, 0);
        
        return go (target, dp);
    }
};
