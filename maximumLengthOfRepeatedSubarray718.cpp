class Solution {
public:
    vector<vector<bool>>dp;
    int l1, l2;

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        l1 = nums1.size();
        l2 = nums2.size();
        int ans = 0;
        dp = vector<vector<bool>>(l1, vector<bool>(l2, false));
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                if (nums1[i] == nums2[j] && !dp[i][j]) {
                    int a = i, b = j, count = 0;
                    while (a < l1 && b < l2 && nums1[a] == nums2[b]) {
                        dp[a][b] = true;
                        a++;b++;
                        count++;
                    }
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};
