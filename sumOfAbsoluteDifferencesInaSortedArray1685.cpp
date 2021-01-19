/*
Absolute difference is the same as max(a, b) - min(a, b). How can you use this fact with the fact that the array is sorted?
For nums[i], the answer is (nums[i] - nums[0]) + (nums[i] - nums[1]) + ... + (nums[i] - nums[i-1]) + (nums[i+1] - nums[i]) + (nums[i+2] - nums[i]) + ... + (nums[n-1] - nums[i]).
It can be simplified to (nums[i] * i - (nums[0] + nums[1] + ... + nums[i-1])) + ((nums[i+1] + nums[i+2] + ... + nums[n-1]) - nums[i] * (n-i-1)). One can build prefix and suffix sums to compute this quickly.
*/
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>sum(nums.size(),0), ans;
        int s = 0, tmp;
        for (int i = 0; i < nums.size(); i++) {
            s+=nums[i];
            sum[i] = s;
        }

        for (int i = 0; i < nums.size(); i++) {
            tmp = (i + 1)* nums[i] - sum[i];
            tmp+=sum.back() - sum[i] - (nums.size() - i - 1) * nums[i];
            ans.push_back(tmp);
        }
        return ans;
    }
};
