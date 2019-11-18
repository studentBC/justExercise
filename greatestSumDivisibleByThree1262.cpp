class Solution {
public: 
    int maxSumDivThree(vector<int>& nums) {
        vector<int>dp = {0,0,0}, prev;
        int index, sum; 
        for (int i = 0; i < nums.size(); i++) {
            prev = dp;
            for (int j : prev) {
                sum = nums[i]+ j;
                index = sum%3;
                dp[index] = max (dp[index], sum);
            }
        }
        return dp[0];
    }
};

