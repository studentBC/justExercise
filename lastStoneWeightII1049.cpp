/*
This question eaquals to partition an array into 2 subsets whose difference is minimal
(1) S1 + S2  = S
(2) S1 - S2 = diff  

==> -> diff = S - 2 * S2  ==> minimize diff equals to  maximize S2 

Now we should find the maximum of S2 , range from 0 to S / 2, using dp can solve this

dp[i][j]   = {true if some subset from 1st to j'th has a sum equal to sum i, false otherwise}
    i ranges from (sum of all elements) {1..n}
    j ranges from  {1..n}


One way to understand the fact that "The minimum result of cancellation = the minimum difference between the sum of two groups".
Say you've already found two groups with smallest difference.
Group A = [A1, A2, ..., An]
Group B = [B1, B2, ..., Bm]
The process we cancel two stones is to arbitrarily pick one from group A and one from Group B.
If Ai > Bj, then put Ai-Bj into group A.
If Ai < Bj, then put Ai-Bj into group B.
If Ai = Bj, then nothing will be put into group A and B.
We repeat the process until there is only one stone left. You will find the remaining stone is |sum(Group A) - sum(Group B)|.
 */
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
	int sum = 0, ans = 0, len = stones.size(), half = len/2;
	for (int i : stones) sum+=i;
       vector<vector<bool>>dp(sum+1, vector<bool>(len+1, false));
       for (int i = 0; i <= len; i++) dp[0][i] = true;
        for (int i = 1; i <= len; ++i) {
            for (int s = 1; s <= half; s++) {
		if (dp[s][i-1] || (s >= stones[i-1] && dp[s-stones[i-1]][i-1])) {
			dp[s][i] = true;
			ans = max(ans, s);
		}
            }
        }
        return sum-2*ans;
    }
};

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int half, sum = 0, len = stones.size();
        for (int i : stones) sum+=i;
        half = sum/2;
        vector<vector<int>>dp(len+1, vector<int>(half+1, 0));
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j <= half; j++) {
                if (j >= stones[i-1]) {
                    dp[i][j] = max(dp[i-1][j], stones[i-1]+dp[i-1][j-stones[i-1]]);
                } else dp[i][j] = dp[i-1][j];
            }
        }
        
        return sum-dp.back().back()*2;
    }
};
/*the fatest method
 *Intuition
Same problem as:
Divide all numbers into two groups,
what is the minimum difference between the sum of two groups.
Now it's a easy classic knapsack problem.


Brief Prove
All cases of "cancellation of rocks" can be expressed by two knapsacks.
And the last stone value equals to the difference of these two knapsacks
It needs to be noticed that the opposite proposition is wrong.

Solution 1
Explanation:
Very classic knapsack problem solved by DP.
In this solution, I use dp to record the achievable sum of the smaller group.
dp[x] = 1 means the sum x is possible.


Time Complexity:
O(NS) time,
O(S) space, where S = sum(A).
 *
 *
 */
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        bitset<1501> dp = {1};
        int sumA = 0, res = 100;
        for (int a : stones) {
            sumA += a;
            for (int i = sumA; i >= a; --i)
                dp[i] = dp[i] + dp[i - a];
        }
        for (int i = sumA / 2; i > 0; --i)
            if (dp[i]) return sumA - i - i;
        return 0;  
    }
};

