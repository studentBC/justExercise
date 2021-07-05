//using kadane's algs to solve
//https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int s = 0, ans = 0, len = nums.size(), big, small;
        vector<int>localMax(len, INT_MIN);
        vector<int>localMin(len, INT_MAX);
        big = small = localMax[0] = localMin[0] = nums[0];
        for (int i = 1; i < len; i++) {
            localMax[i] = max(nums[i], nums[i]+localMax[i-1]);
            big = max(big, localMax[i]);
            localMin[i] = min(nums[i], nums[i]+localMin[i-1]);
            small = min(small, localMin[i]);
        }
        return max(abs(big), abs(small));
    }
};
