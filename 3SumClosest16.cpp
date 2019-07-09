/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int small = INT_MAX, ans = target, temp;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            int find = target-nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back) {

                int sum = nums[front] + nums[back];
                temp = sum+nums[i];
                if (abs(temp-target) < small) {
                    small = abs(temp-target);
                    ans = temp;
                }
                // Finding answer which start from number num[i]
                if (sum < find) {
                    front++;
                } else if (sum > find) {
                    back--;
                } else if (sum == find) {
                    //cout <<"found !!" << endl;
                    return target;
                }
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int sum;
        int size = nums.size();
        int j, k;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size-2; i++) {
            j = i + 1;
            k = size - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                }
                else if (sum > target) {
                    if (abs(sum-target) < abs(closest-target))
                        closest = sum;
                    k--;
                }
                else { // sum < target
                    if (abs(sum-target) < abs(closest-target))
                        closest = sum;
                    j++;                    
                }
            }
        }
        return closest;
    }
};
