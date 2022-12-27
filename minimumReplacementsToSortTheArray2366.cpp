/*
 *
We should probably split as little as we possibly can, since this is an optimization problem on the number of splits.
This fact is important to us when splitting: for any positive integer n and all 1 <= k <= n, it's possible to represent n as the sum of k numbers, such that all numbers differ by no more than 1.
*/
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int prev = nums.back(), count;
        for (int i = nums.size()-2; i > -1; i--) {
            count = nums[i]/prev;
            if (nums[i]%prev) {
                count++;
                prev = nums[i]/count;
            }
            ans+=count-1;
        }
        return ans;
    }
};
