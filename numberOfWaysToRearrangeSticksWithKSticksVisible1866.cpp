/*
Another way to think about this problem is to assign a stick to the rightmost position first. After selecting a stick for the rightmost position, we will be left with n - 1 sticks of different sizes that will go on its left and there will be no restriction imposed by the stick we selected to be at the rightmost position. We just need to track whether the stick we selected at the rightmost position will be visible from the left side or not. And figuring that out is easy. It will be visible from the left side if it was the tallest of all the sticks we had. And it will not be visible from the left if it wasn't the tallest stick. So the two possibilities for the rightmost stick selection at any point where we have n sticks and k of them need to be visible from the left:

We select the tallest of the n sticks. There's only one such stick and this stick will finally be visible from the left. And so we are left with the sub-problem (n - 1, k - 1).
We select a stick that's not the tallest one. We can do this by selecting any of the n - 1 sticks that are not the tallest one. So there are n - 1 sub-problems and each of them is (n - 1, k). This stick we selected will not be visible from the left, so we still gotta select k sticks from the remaining pile that will be visible, that's why the sub-problem has k, and not k - 1.
*/
class Solution {
public:
	int mod = 1e9+7;
	vector<long long>dp;
	long long go (int n, int k) {
		if (k == 0 || k > n) return 0;
		if (n <= 2) return 1;
		if (dp[n][k] > -1) return dp[n][k];
		long long ans = 0;
		ans = (ans+go(n-1, k-1))%mod;
//We are using the same logic in our solution. dp[n][k] = number of ways to arrange n sticks such that k are visible from the left. Then for case number 2 (as described in the solution), the number of ways we can select a non-tallest stick = n - 1. And number of ways of arranging what's left = dp[n - 1][k]. So we multiple these two.
		ans = (ans+(n-1)*go(n-1, k))%mod;
		return dp[n][k] = ans;
	}
    int rearrangeSticks(int n, int k) {
        dp = vector<vector<long long>>(n+1, vector<long long>(k+1, -1));
		return go (n, k);
    }
};
