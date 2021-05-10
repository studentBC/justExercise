//https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
 	sort(nums.begin(), nums.end());
	int ans = 0;
	long sum = k;
	for (int j = 0, i = 0; j < nums.size(); j++) {
		sum+=nums[j];
		if (sum < (long)nums[j]*(j-i+1)) {
			sum-=nums[i];
			i++;
		} else ans = max(ans, j-i+1);
	}
	return ans;
    }
};
//140 ms solution
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 1;
        int x = 0;
        int s = 0;
        for (int i = 1; i < (int) nums.size(); ++i) {
            s += (i - x) * (nums[i] - nums[i-1]);
            while (s > k) {
                s -= nums[i] - nums[x];
                ++x;
            }
            res = max(res, i - x + 1);
        }
        return res;
    }
};
