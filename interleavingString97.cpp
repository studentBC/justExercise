class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size()+s2.size() != s3.size()) return false;
        if(s3.size() == 0) {
            return true;
        } else if (s2.size() == 0) {
            if (s1 == s3) return true;
            return false;
        } else if (s1.size() == 0) {
            if (s2 == s3) return true;
            return false;
        }
        vector<vector<bool>>dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0 ) {
                    if (dp[i][j-1] && s2[j-1] == s3[j-1]) dp[i][j] = true;
                } else if (j == 0 ) {
                    if (dp[i-1][j] && s1[i-1] == s3[i-1]) dp[i][j] = true;
                } else {
                    if ((dp[i][j-1] && s2[j-1] == s3[i+j-1]) || (dp[i-1][j] && s1[i-1] == s3[i+j-1])) dp[i][j] = true;
                }
            }
        }
        return dp.back().back();
    }
};
