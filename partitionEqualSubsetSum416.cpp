/*
 Actually, this is a 0/1 knapsack problem, for each number, we can pick it or not. Let us assume dp[i][j] means whether the specific sum j can be gotten from the first i numbers. If we can pick such a series of numbers from 0-i whose sum is j, dp[i][j] is true, otherwise it is false.

Base case: dp[0][0] is true; (zero number consists of sum 0 is true)

Transition function: For each number, if we don't pick it, dp[i][j] = dp[i-1][j], which means if the first i-1 elements has made it to j, dp[i][j] would also make it to j (we can just ignore nums[i]). If we pick nums[i]. dp[i][j] = dp[i-1][j-nums[i]], which represents that j is composed of the current value nums[i] and the remaining composed of other previous numbers. Thus, the transition function is dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
		int sum = 0, len = nums.size();
		for (int i : nums) sum+=i;
		if (sum&1) return false;
		sum>>=1;
		vector<vector<bool>>dp(len+1, vector<bool>(sum+1, false));
		dp[0][0] = true;
		for (int i = 1; i <= len; i++) dp[i][0] = 0;
		for (int i = 1; i <= sum; i++) dp[0][i] = 0;
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= sum; j++) {
				dp[i][j] = dp[i-1][j];
				if (j >= nums[i-1]) dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
			}
		}
		return dp[len][sum];
    }
};
