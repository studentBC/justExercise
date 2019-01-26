class Solution {
public:
    /*int tmin (int a, int b, int c) {
        if (a < b) {
            if (a < c) {
                return a;
            } else {
                return c;
            }
        } else {
            if (b < c) {
                return b;
            } else {
                return c;
            }
        }
    }*/
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s2.size()+1,vector<int>(s1.size()+1, 0));
        dp[0][0] = 0;
        for (int i = 1; i <= s1.size(); i++) {
            dp[0][i] = dp[0][i-1]+s1[i-1];
            //cout << dp[0][i] <<" , ";
        }
        //cout<<endl;
        for (int i = 1; i <= s2.size(); i++) {
            dp[i][0] = dp[i-1][0]+s2[i-1];
            //cout << dp[i][0] <<" , ";
        }
        //cout<<endl;
        for (int i = 1; i <= s2.size(); i++) {
            for (int j = 1; j <= s1.size(); j++) {
                if (s2[i-1] == s1[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    //dp[i][j]=max(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1] , dp[i-1][j]-dp[i][j-1]+dp[i-1][j-1]);
                    dp[i][j] = min( dp[i][j-1]+s1[j-1] , dp[i-1][j]+s2[i-1]);
                }
                //cout << dp[i][j] <<" , ";
            }
            //cout<<endl;
        }
        return dp[s2.size()][s1.size()];
    }
};
