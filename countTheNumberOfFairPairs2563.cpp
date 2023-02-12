class Solution {
public:
    long long count  (vector<int>& nums, int target) {
        long long ans = 0;
        for (int i = 0, j = nums.size()-1; i < j; i++) {
            while (i < j && nums[i] + nums[j] > target) j--;
            ans+=(j-i);
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return count(nums, upper) - count(nums, lower-1);
    }
};
