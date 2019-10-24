/*
define dp[i][j] : until i-th coins, the probability to get j heads.

example1 dp[3][1] : only 1 head when tossing first 3 coins
only 1 head when tossing first 3 coins = 
   only 1 head when tossing first 2 coins and third coins is not head + 
   no head when tossing first 2 coins and third coins is head
Thus, dp[3][1] =  dp[2][0] * prob[3]  +  dp[2][1] * (1-prob[3])
*/
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<vector<double> > dp(prob.size() + 1, vector<double>(target + 1, 0));
        dp[0][0] = 1.0;
        for (int i = 1; i <= prob.size(); i++) {
            dp[i][0] = dp[i-1][0]*(1-prob[i-1]);
        }
        for (int i = 1; i <= prob.size(); i++) {
            for (int j = 1; j <= min(target, i); j++) {
                dp[i][j] = dp[i-1][j-1]*prob[i-1] + dp[i-1][j]*(1-prob[i-1]);
            }
        }
        /*
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                cout << dp[i][j] <<" , ";
            }
            cout << endl;
        }*/
        return dp.back().back();
    }
};
//the fatest solution
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<double> dp(target + 1);
        dp[0] = 1.0;
        
        for (int i = 0; i < prob.size(); i++) {
            for (int j = min(i+1, target); j >= 0; j--) {
                dp[j] = dp[j] * (1 - prob[i]) + (j ? dp[j-1] : 0) * prob[i];
            }
        }
        return dp[target];
    }
};
