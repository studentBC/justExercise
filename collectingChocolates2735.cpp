class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int len = nums.size(), cost;
        vector<long long>ans(len, 0);
        for (int i = 0; i < len; i++) {
            ans[i]+=1L*i*x;
            cost = nums[i];
            for (int j = 0; j < len; j++) {
                cost = min(cost, nums[(i-j+len)%len]);
                ans[j]+=cost;
            }
        }
        return *min_element(ans.begin(), ans.end());
    }
};
