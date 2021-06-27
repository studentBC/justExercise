class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even = 0, odd = 0;
        for (int i = 0; i < nums.size(); i++)  {
            even = max(even, odd+nums[i]);
            odd = even-nums[i];
        }
        
        return max(even, odd);
    }
};
