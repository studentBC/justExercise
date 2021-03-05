class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        //vector<int>sum(nums.size(), 0);
        int small = 0, s = 0, big = 0;
        for (int i = 0; i < nums.size(); i++) {
            s+=nums[i];
            //sum[i] = s;
            small = min(s, small);
            big = max(s, big);
        }
        
        return abs(big-small);
    }
};
