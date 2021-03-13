//https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/discuss/780882/Java-14-lines-Greedy-PrefixSum-with-line-by-line-explanation-easy-to-understand
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int ans = 0, sum = 0;
        unordered_map<int,int>dp;
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum+=nums[i];
            if (dp.count(sum-target)) ans = max(ans, dp[sum-target]+1);
            dp[sum] = ans;
        }
        return ans;
    }
};

