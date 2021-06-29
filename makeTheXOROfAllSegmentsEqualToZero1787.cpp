class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
 	int freq[k][1024], len = nums.size();
	memset(freq, 0, sizeof freq);
	unordered_set<int>uniq[k];
	int index;
	for (int i = 0; i < len; i++) {
		index = i%k;
		freq[index][nums[i]]++;
		uniq[index].insert(nums[i]);
	}
	vector<vector<int>> dp(k, vector<int>(1024, len+1));
	int prevMin = 0, totalSame, small;
	for (int i = 0; i < k; i++) {
		totalSame = n/k+((n%k) > i?1:0);
		small = len+1;
		for (int j = 0; j < 1024; j++) {
			if (!i) dp[i][j] = totalSame - freq[i][j];
			else {
				for (int x : uniq[i]) {
					dp[i][j] = min(dp[i][j], dp[i-1][j^x]+totalSame-freq[i][x]);
				}
				dp[i][j] = min(dp[i][j], prevMin+totalSame);
			}
			small = min(small, dp[i][j]);
		}
		prevMin = small;
	}
	return dp[k][0];
    }
};
//https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/discuss/1099112/C%2B%2B-An-easy-solution-with-detailed-explanation-to-a-really-hard-problem
