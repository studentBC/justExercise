/*
Intuition
The connected two points in polygon shares one common edge,
these two points must be one and only one triangles.


Explanation
dp[i][j] means the minimum score to triangulate A[i] ~ A[j],
while there is edge connect A[i] and A[j].

We enumerate all points A[k] with i < k < j to form a triangle.

The score of this triangulation is dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]
*/ 
int minScoreTriangulation(vector<int>& A) {
	int n = A.size();
	vector<vector<int>> dp(n, vector<int>(n));
	for (int j = 2; j < n; ++j) {
		for (int i = j - 2; i >= 0; --i) {
			dp[i][j] = INT_MAX;
			for (int k = i + 1; k < j; ++k)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]);
		}
	}
	return dp[0][n - 1];
}
//fatest method
class Solution {
public:
    int minScoreTriangulation(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int dis = 2; dis <= n - 1; ++dis) {
            for (int i = 0; i + dis < n; ++i) {
                int j = i + dis;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
