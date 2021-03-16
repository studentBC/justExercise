class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k], i = k, j = k, left, right, small = nums[k];
        while (i > 0 || j+1 < nums.size()) {
            if (i) left= nums[i-1];
            else left = 0;
            if (j+1 < nums.size() ) right= nums[j+1];
            else right = 0;
            if (left < right) small = min(small, nums[++j]);
            else small = min(small, nums[--i]);
            ans = max(ans, small*(j-i+1));
        }
        return ans;
    }
};
