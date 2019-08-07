/*
Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:
Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
    After flipping, the maximum number of consecutive 1s is 4.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
Follow up:
What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?

wrong test case:
[0]
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, flip, ans = 0;
        if (nums[0]) {
            flip = 1;
        } else {
            flip = 0;
        }
        ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (!nums[i]) {
                if (flip) {
                    flip = 0;
                } else { 
                    for (int j = left; j <= i; j++) {
                        if (!nums[j]) {
                            left = j+1;
                            break;
                        }
                    }
                    if (nums[left]) flip = 1;
                    if (!nums[i]) flip = 0;
                }
            }
            ans = max (ans, i-left+1);
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
    }
    
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int last = 0;
        int count = 0;
        int result = 0;
        for (auto n : nums) {
            if (n == 1) {
                count++;
            } else {
                if (last) {
                    count++;
                    count = count - last;
                    last = count;
                } else {
                    count++;
                    last = count;
                }
            }
            //printf("count=%d last=%d\n", count, last);
            result = max(result, count);
        }
        
        return result;
    }
};
