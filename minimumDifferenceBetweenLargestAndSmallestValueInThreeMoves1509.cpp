class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <=4)
            return 0;
        // //we can sort the whole vector
        // sort(nums.begin(), nums.end());
        
        //or partial sort 3 smallest and 3 largest only
        partial_sort(nums.begin(), nums.begin()+4, nums.end());
        partial_sort(nums.rbegin(), nums.rbegin()+4, nums.rend(), greater<int>());
        
        //exclude 3 smallest
        int res = nums[n-1] - nums[3];
        
        //2 smallest and 1 largest
        res = min(res, nums[n-2] - nums[2]);
        
        // 1 small 2 largest
        res = min(res, nums[n-3] - nums[1]);
        
        //all larger
        res = min(res, nums[n-4] - nums[0]);
        
        return res;
        
    }
};
