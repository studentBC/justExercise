//my TLE version
class Solution {
public:
    int go (int pos, vector<int>& dp, vector<int>& nums, int& k) {
        if (pos < 0) return INT_MIN;
        if (dp[pos]!=INT_MIN) return dp[pos];
        int end = pos-k;
        for (int i = pos-1; i >= end; i--) {
            dp[pos] = max(go (i, dp, nums, k), dp[pos]);
        }
        
        return dp[pos]+=nums[pos];
    }
    int maxResult(vector<int>& nums, int k) {
        vector<int>dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        return go (nums.size()-1, dp, nums, k);
    }
};
//beat 91%
class Solution {
public:

    int maxResult(vector<int>& nums, int k) {
        int ans = nums[0];
        deque<int>dq;
        for (int i = 0; i < nums.size(); i++) {
            ans = nums[i]+(dq.empty()?0:nums[dq.front()]);
            while (!dq.empty() && ans > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if (dq.front() <= i-k) dq.pop_front();
            nums[i] = ans;
        }
        return ans;
    }
};
