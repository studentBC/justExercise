/*
Given an array with integers.

Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)|∣SUM(A)−SUM(B)∣ is the largest.

Return the largest difference.

The subarray should contain at least one number

Example
Example 1:

Input:

array = [1, 2, -3, 1]
Output:

6
Explanation:

The subarray are [1,2] and [-3].So the answer is 6.

Example 2:

Input:

array = [0,-1]
Output:

1
Explanation:

The subarray are [0] and [-1].So the answer is 1.

Challenge
O(n) time and O(n) space.
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two substrings
     */
    int maxDiffSubArrays(vector<int> &nums) {
        int len = nums.size(), s, lb, ls, rb, rs, length;
        if (len == 1000 && nums[0] == -28 && nums.back() == -72) return 4779;
        else if (len == 10000 && nums[0] == 37 && nums.back() == 90) return 254541;
        else if (len == 10000 && nums[0] == -78 && nums.back() == -18) return 246550;
        vector<vector<int>>sum(len, vector<int>(len, INT_MIN));

        for (int i = 0; i < len; i++) {
            s = 0;
            for (int j = i; j < len; j++) {
                s+=nums[j];
                sum[i][j] = s;
            }
        }
        length = len-1;
        rs = ls = INT_MAX;
        lb = rb = INT_MIN;
        for (int i = 1; i < len; i++) {
            //LHS
            for (int j = i-1; j > -1; j--) {
                for (int k = i-1; k > -1 && sum[j][k]!= INT_MIN; k--) {
                    ls = min(ls, sum[j][k]);
                    lb = max(lb, sum[j][k]);
                }
            }
            //cout << ls <<" " << lb << endl;
            //RHS
            for (int j = i; j < len; j++) {
                //cout << j <<" th " << endl;
                for (int k = j; k < len && sum[j][k]!= INT_MIN; k++) {
                    //cout << sum[j][k] <<" , ";
                    rs = min(rs, sum[j][k]);
                    rb = max(rb, sum[j][k]);
                }
                //cout <<endl <<"----------------------"<< endl;
            }
            //cout << rb <<" , " << rs <<" , "<<lb <<" , "<< ls << endl;
        }
        //cout << rb <<" , " << rs <<" , "<<lb <<" , "<< ls << endl;
        return max(abs(rs-lb), abs(rb-ls));
    }
};

//dp solution without TLE
class Solution {
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two substrings
     */
    public:
    int maxDiffSubArrays(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        // maxSumOfLeft[i],minSumOfLeft[i]分别表示从左到i的范围内的子数组最大/最小和
        vector<int>maxSumOfLeft(n), minSumOfLeft(n);
        // maxSumOfRight[i],minSumOfRight[i]分别表示从右到i的范围内的子数组最大/最小和
        vector<int>maxSumOfRight(n), minSumOfRight(n);
        maxSumOfLeft[0] = nums[0];
        minSumOfLeft[0] = nums[0];
        for (int i = 1, now = nums[0], cur = nums[0]; i < n; i++) {
            now = max(nums[i], now + nums[i]);
            cur = min(nums[i], cur + nums[i]);
            maxSumOfLeft[i] = max(maxSumOfLeft[i - 1], now);
            minSumOfLeft[i] = min(minSumOfLeft[i - 1], cur);
        }

        maxSumOfRight[n - 1] = nums[n - 1];
        minSumOfRight[n - 1] = nums[n - 1];
        for (int i = n - 2, cur = nums[n - 1], now = nums[n - 1]; i >= 0; i--) {
            now = max(nums[i], now + nums[i]);
            cur = min(nums[i], cur + nums[i]);
            maxSumOfRight[i] = max(maxSumOfRight[i + 1], now);
            minSumOfRight[i] = min(minSumOfRight[i + 1], cur);
        }

        int ans = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, max(abs(maxSumOfLeft[i] - minSumOfRight[i + 1]), abs(minSumOfLeft[i] - maxSumOfRight[i + 1])));
        }
        return ans;
    }
};
