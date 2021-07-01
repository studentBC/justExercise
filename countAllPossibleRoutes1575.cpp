class Solution {
public:
    int mod = 1e9+7, len, end;
    unordered_map<int, unordered_map<int, int>>cost;
    int go (int start, int fuel, vector<int>& locations, vector<vector<int>>& dp) {
        if (fuel < 0) return 0;
        else if (dp[start][fuel] > -1) return dp[start][fuel];
        long long ans = 0;
        if (start == end)  ans = 1;
        for (int i = 0; i < len; i++) {
            if (i!=start) {
                ans += go (i, fuel-cost[start][i], locations, dp)%mod;
                ans%=mod;
            }
        }
        return dp[start][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>>dp(locations.size(), vector<int>(fuel+1, -1));
        len = locations.size(); end = finish;
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                cost[j][i] = cost[i][j] = abs(locations[i]-locations[j]);
            }
        }
        return go (start, fuel, locations, dp);
    }
};
