//https://leetcode.com/problems/maximum-and-sum-of-array/discuss/1766743/C%2B%2B-Short-Bitmask-DP
/*
Algorithm:

Append 0s to make sure the length of A is 2 * numSlots.

Let dp[m] be the maximum score given a bitmask m representing the selected numbers. The final answer is dp[(1 << N) - 1].

Assume m's i-th bit is 1, we have the following formula:

dp[m] = max( dp[m - (1 << i)] + (slotNumber & A[i]) | m's i-th bit is 1 )
                        where slotNumber = (cnt + 1) / 2 and cnt = bitCount(m)
The key is that we always make this picked A[i] as the last element of all elements in m and assign it to slotNumber-th slot, and slotNumber is a constant given m.

Why slotNumber = (cnt + 1) / 2?

If cnt = 1, we put this first element at slot 1.
If cnt = 2 meaning two elements are selected, we pick one of them as the last element and put it in slot 1.
If cnt = 3 meaning three elements are seledted, we pick one of them as the last element and put it in slot 2.
ans so on...
So the cnt to slotNumber mapping is 1 or 2 -> 1, 3 or 4 -> 2, ... i.e. slotNumber = (cnt + 1) / 2.

Example of State Transition:

Assume m = 1101, we'll assign A[i] to slot (bitCount(m) + 1) / 2 = (3 + 1) / 2 = 2:

If i = 0, dp[1101] = dp[1100] + (2 & A[0])
If i = 2, dp[1101] = dp[1001] + (2 & A[2])
If i = 3, dp[1101] = dp[0101] + (2 & A[3]).
*/ 
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        nums.resize(2*numSlots);
        int len = nums.size(), count, slot;
        vector<int>dp(1<<len);
        for (int m = 1; m < 1<<len; m++) {
            //a function in C++ returns the number of 1-bits set in an int x.
            count = __builtin_popcount(m), slot = (count+1)/2;
            for (int i = 0; i < len; i++) {
                if (m >> i & 1) {
                    dp[m] = max(dp[m], dp[m^(1<<i)]+(slot&nums[i]));
                }
            }
        }
        return dp[(1<<len)-1];
    }
};
