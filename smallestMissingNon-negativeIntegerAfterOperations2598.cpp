/*
For an element n, we can achieve the minimum non-negative value of n % value.

We can also transform element n to n % value + k * value.

We first count moduli we can get from all numbers.

Then, we iterate i from zero upwards, and check if we have a modulo that we can tranform to i.
*/

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int dp[100001] = {}, len = nums.size();
        for (int i : nums) ++dp[(value+i%value)%value];
        for (int i = 0; i < len; i++) {
            if (--dp[i%value] < 0) return i;
        }
        return len;
    }
};
