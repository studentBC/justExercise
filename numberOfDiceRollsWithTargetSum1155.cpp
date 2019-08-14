class Solution {
public:
    int go (int d, int f, vector<vector<int>>& dp, int target) {
        //cout << d <<" , "<<target << endl;
        if (d == 0 || target <= 0) {
            return target == d;
        }
        if (dp[d][target] > -1) return dp[d][target];
        int sum = 0;
        for (int i = 1; i <= f; i++) {
            if (target >= i) {
                sum = (sum + go(d-1, f, dp, target-i))%1000000007;
            } else {
                break;
            }
        }
        dp[d][target] = sum;
        return sum;
    }
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>>dp(d+1, vector<int>(max(f, target)+1,-1));

        return go (d, f, dp, target);
    }
};
//concept solution
int numRollsToTarget(int d, int f, int target) {
  vector<int> dp(target + 1);
  dp[0] = 1;
  for (int i = 1; i <= d; ++i) {
    vector<int> dp1(target + 1);
    for (int j = 1; j <= f; ++j)
      for (auto k = j; k <= target; ++k)
        dp1[k] = (dp1[k] + dp[k - j]) % 1000000007;
    swap(dp, dp1);
  }
  return dp[target];
}
//top down approach
int dp[31][1001] = {};
int numRollsToTarget(int d, int f, int target, int res = 0) {
  if (d == 0 || target <= 0) return d == target;
  if (dp[d][target]) return dp[d][target] - 1;
  for (auto i = 1; i <= f; ++i)
    res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
  dp[d][target] = res + 1;
  return res;
}
//the fatest method
class Solution {
public:
    int numRollsToTarget(int d, int f, int target)
    {
        if (target < 0 || target > d * f) return 0;
        vector<int> rolls(1, 1);
        for (int i = 1; i <= d; i++) {
            vector<int> temp(i * f + 1, 0);
            for (int r = 1; r <= f; r++)
                for (int j = 0; j < rolls.size(); j++)
                    temp[j + r] = (temp[j + r] + rolls[j]) % 1000000007;
            rolls.swap(temp);
        }
        return rolls[target];
    }
};
