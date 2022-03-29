class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int,int>>>ride(n);
        for (auto& it: rides) ride[it[0]].push_back({it[1], it[1]- it[0]+it[2]});
        vector<long long>dp(n+1, 0);
        for (int i = n-1; i > 0; i--) {
                for (auto& [e, d] : ride[i]) dp[i] = max(dp[i], dp[e]+d);
                dp[i] = max(dp[i], dp[i+1]);
        }
        return dp[1];
    }
};
//my soultion reach TLE
class Solution {
public:
    long long ans = 0;
    static bool compare (vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), compare);
        int len = rides.size();
        long long earn = 0, pick, res;
        vector<long long >dp(len, 0);
        dp[0] = rides[0][1] -rides[0][0]+rides[0][2];
        //dp.back() = rides.back()[1] -rides.back()[0]+rides.back()[2];
        for (int i = 1; i < len; i++) {
            res = 0;
            for (int j = i-1; j > -1; j--) {
                if (rides[j][1] <= rides[i][0]) {res = max(dp[j], res); break;}
            }
            res+=rides[i][1]-rides[i][0]+rides[i][2];
            dp[i] = max(res, dp[i-1]);
            ans = max(ans, dp[i]);
        }
        return ans;
        return dp.back();
    }
};
