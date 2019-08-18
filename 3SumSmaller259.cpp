/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Example:

Input: nums = [-2,0,1,3], and target = 2
Output: 2 
Explanation: Because there are two triplets which sums are less than 2:
             [-2,0,1]
             [-2,0,3]
Follow up: Could you solve it in O(n2) runtime?

wrong test case:
[-1,1,-1,0]
-1
*/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int fe = nums.size()-3, se = nums.size()-2 , sum, ans = 0;
        for (int i = 0; i <= fe; i++) {
            for (int j = i+1; j <= se; j++) {
                sum=nums[j]+nums[i];
                for (int k = j+1; k < nums.size(); k++) {
                    if (sum+nums[k] < target) ans++;
                }
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        
        int ans = 0;

        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {            
            if (3 * nums[i] > target) {
                break;
            }
            
            int y = target - nums[i]; 

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int x = nums[j] + nums[k];
                if (x < y) {
                    ans += k - j;
                    j++;
                }
                else {
                    k--;
                }
            }
        }

        return ans;
    }
};
