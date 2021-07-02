int coinChange(int* coins, int coinsSize, int amount) {
     int change[amount+1];
     change[0] = 0;
     int min = INT_MAX;
     int left;
     for (int i = 1; i <= amount; i++) {
         min = INT_MAX;
         for (int j = 0; j < coinsSize; j++ ) {
             if (i >= coins[j]) {
                 left = change[i-coins[j]];
                 if (left < min) {
                     min = 1+left;
                 }
             }
         }
         change[i] = min;
     }
     if (change[amount] == INT_MAX) {
         return -1;
     }  
     return change[amount];
}
//cpp solution
class Solution {
public:
    int len;
    int go (int amount, vector<int>& coins, vector<int>& dp) {
        if (amount < 0) return 0;
        else if (dp[amount] > -1) return dp[amount];
        int ans = INT_MAX, left, right;
        //cout << amount <<" , ";
        for (int i = 0; i < len; i++) {
            if (coins[i] <= amount) {
                left = go (coins[i], coins, dp);
                right = go (amount-coins[i], coins, dp);
                if (left == INT_MAX || right == INT_MAX) continue;
                ans = min(ans, left + right);
            }
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -1);
        len = coins.size();
        for (int i : coins) {
            if (i <= amount) dp[i] = 1;
        }
        dp[0] = 0;
        int ans = go (amount, coins, dp);
        return ans == INT_MAX?-1:ans;
    }
};
