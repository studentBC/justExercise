class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>>dp(3,vector<int>(obstacles.size(),INT_MAX));
        dp[2][0] = dp[0][0] = 1;
        dp[1][0] = 0;
        int side;
        for (int i = 1; i < obstacles.size(); i++) {
            side = INT_MAX;
            for (int j = 0; j < 3; j++) {
                if (j != obstacles[i]-1) {
                    dp[j][i] = dp[j][i-1];
                    //cout <<dp[j][i] << " , "<<dp[j][i-1] << endl;
                    side = min(side, dp[j][i]);
                }
            }
            //side = INT_MAX;
            for (int j = 0; j < 3; j++) {
                if (j != obstacles[i]-1) dp[j][i] = min(side+1, dp[j][i]);
                //cout << dp[j][i] <<" , ";
            }
            //cout << endl;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 3; i++) {
            ans = min(ans, dp[i].back());
        }
        return ans;
    }
};
