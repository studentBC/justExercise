class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int>dp(nums.size(),0);
        vector<int>turn(nums.size(),-1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i-1; j > -1; j--) {
                if (turn[j] == 1 && nums[i] > nums[j]) {
                    dp[i] = dp[j]+1;
                    turn[i] = 0;
                    break;
                } else if (turn[j] == 0 && nums[i] < nums[j]) {
                    dp[i] = dp[j]+1;
                    turn[i] = 1;
                    break;
                } else if (turn[j] == -1) {
                    if (nums[j] > nums[i]) {
                        turn[i] = 1;
                        dp[i] = dp[j]+1;
                    } else if (nums[j] < nums[i]) {
                        turn[i] = 0;
                        dp[i] = dp[j]+1;
                    }
                }
            }
        }
        return dp[nums.size()-1]+1;
    }
};

