/*
 * Given a sorted array of integers nums and integer values a, b and c. Apply a quadratic function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example 1:

Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]

Example 2:

Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]
 */
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
		vector<int>ans;
		for (int i : nums) {
			ans.emplace_back(a*i*i+b*i+c);
		}
		sort(ans.begin(), ans.end());
		return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size(), l = 0, r = n - 1;
        vector<int> res(n);
        int id = a > 0 ? n - 1 : 0;
        while (n-- > 0) {
            int left = a * nums[l] * nums[l] + b * nums[l] + c;
            int right = a * nums[r] * nums[r] + b * nums[r] + c;
            if (left < right) {
                if (a > 0) {
                    res[id--] = right;
                    r--;
                }
                else {
                    res[id++] = left;
                    l++;
                }
            }
            else {
                if (a > 0) {
                    res[id--] = left;
                    l++;
                }
                else {
                    res[id++] = right;
                    r--;
                }
            }
        }
        return res;
    }
};
