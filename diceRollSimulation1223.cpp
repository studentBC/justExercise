class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<long>>dp(n,vector<long>(7,1));
        long long sum, ans = 0;
        dp[0][6] = 6;
        for (int i = 1; i < n; i++) {
            sum = 0;
            for (int j = 0; j < 6; j++) {
                if (i < rollMax[j]) {
                    dp[i][j] = dp[i-1][6]%1000000007;
                } else {
                    if (i > rollMax[j]) {
                        dp[i][j] = (dp[i-1][6]-(dp[i-rollMax[j]-1][6]-dp[i-rollMax[j]-1][j]))%1000000007+1000000007;
                    } else {
                        dp[i][j] = (dp[i-1][6]-1)%1000000007;
                    }
                }
                sum+=dp[i][j];
                sum%=1000000007;
                //sum+=1000000007;
                //cout << dp[i][j] <<" , ";
            }
            dp[i][6] = sum;
            //cout << endl;
        }
        return dp.back().back();
    }
};
//the fatest solution
#define MOD 1000000007
class Solution {
public:
    int dieSimulator(int N, vector<int>& A) {
        int dp[N][7];
        for(int i = 0; i < 6; i++)
            dp[0][i] = 1;
        dp[0][6] = 6;
        // Roll of dice ith time
        for(int i = 1; i < N; i++){
            long long sum = 0;
            for(int j = 0; j < 6; j++){
                dp[i][j] = dp[i-1][6];
                if(i >= A[j])
                {
                    if(i >= A[j] + 1){
                        int temp = dp[i - A[j] - 1][6] - dp[i - A[j] - 1][j];
                        dp[i][j] = ((dp[i][j] - temp) % MOD + MOD) % MOD;
                    }
                    else dp[i][j]--;
                } 
                sum = (sum + dp[i][j]) % MOD;
            }
            dp[i][6] = sum;
        }
        return (int)dp[N-1][6];
    }
};
