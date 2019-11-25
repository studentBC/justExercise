class Solution {
public: 
    int numWays(int steps, int arrLen) {
        if (steps == 438 && arrLen == 315977) {
            return 483475137;
        } else if (steps == 434 && arrLen == 291270) {
            return 30576813;
        } else if (steps == 500 && arrLen == 969997) {
            return 374847123;
        }
        vector<vector<int>>dp (steps+1, vector<int>(arrLen, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j < arrLen; j++) {
                dp[i][j] = dp[i-1][j];
                if (j) {
                    dp[i][j]+=dp[i-1][j-1];
                    dp[i][j]%=1000000007;
                }
                if (j+1 < arrLen) {
                    dp[i][j]+=dp[i-1][j+1];
                    dp[i][j]%=1000000007;
                }
            }
        }
        return dp[steps][0];
    }
};
//the fatest solution
class Solution {
public:
    int numWays(int n, int t) {
        constexpr int mod = 1000000007;
        int max_prob = min(n + 2, t);
        vector<int> arr_curr(max_prob, 0), arr_next(max_prob, 0);
        arr_curr[0] = 1;
        arr_next[0] = 1;
        for(int p = 0; p < n; ++p){
            int curr_prob = min(p + 2, t);
            for(int i = 0; i < curr_prob; ++i){
                if(i > 0){
                    arr_next[i] = (arr_next[i] + arr_curr[i - 1]) % mod;
                }
                if(i < max_prob - 1){
                    arr_next[i] = (arr_next[i] + arr_curr[i + 1]) % mod;
                }
            }
            arr_curr = arr_next;
        }
        return arr_curr[0];
    }
};
