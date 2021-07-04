class Solution {
public:
    int dp[16384] = {[0 ... 16383] = INT_MAX};
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2, int i = 0, int mask = 0) {
        if (i>=nums1.size()) return 0;
        if (dp[mask] == INT_MAX) {
            for (int j = 0; j < nums2.size(); j++) {
                if ( ((1<<j)&mask) == 0) dp[mask] = min(dp[mask], (nums1[i] ^ nums2[j]) + minimumXORSum(nums1, nums2, i+1, mask+(1<<j)));
            }
        }
        return dp[mask];
    }
};
