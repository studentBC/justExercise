class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long res = 0, len = questions.size(), ans = 0;
        vector<long long>dp(len, 0);
        ans = dp.back() = questions.back()[0];
        for (int i = len-2; i > -1; i--) {
            if (i+questions[i][1]+1 < len) res = dp[i+questions[i][1]+1];
            else res = 0;
            dp[i] = max(dp[i+1], questions[i][0]+res);
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

//the 260 ms solution
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        // dp[i]
        vector<long long> dp(n, -1);
        return dfs(dp, questions, 0);
    }
    long long dfs(vector<long long>& dp, vector<vector<int>>& questions, int i){
        if (i>=questions.size())
            return 0;
        if (dp[i]>-1)
            return dp[i];
        else
            return dp[i] = max(
                dfs(dp, questions, i+1),
                questions[i][0] + dfs(dp, questions, i+questions[i][1]+1)
            );
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
