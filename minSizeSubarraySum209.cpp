/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int length = INT_MAX, sum = 0, left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= s) return 1;
            sum+=nums[i];
            if (sum >= s) {
                while (sum-nums[left] >= s) {
					sum-=nums[left];
                    left++;
                }
                length = min (length, i - left + 1);
            }
        }
        if (length == INT_MAX) return 0;
        return length;
    }
};
//the fatest method
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int curSum = 0;
        int minLength = INT_MAX;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            curSum += nums[j];
            while (curSum >= s) {
                minLength = min(minLength, j - i + 1);
                curSum -= nums[i++];
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};
