/*
suppose n=5, then Alice's gain is a1+a3+a5 where a1 means the 1st round's gain for Alice. Bob's gain is b2+b4. The final difference is (a1+a3+a5)-(b2+b4) which can be rewritten as a1-(b2-(a3-(b4-a5))). If we realize that a1>b2>a3>b4>a5, we know this is actually a recursive pattern. The optimal strategy for both players is to maximize my_current_round_gain - subproblem_difference. Alice wants to maximize a1-subproblem, so Alice wants to maximize a3-subproblem due to the double negation. The same for Bob. Bob wants to minimize a1-subproblem, so Bob wants to maximize b2-subproblem, then maximize b4-subproblem due to double negation. This insight will help reduce the complexity a lot since we only need one DP instead of two.

We don't need to keep track of turns because, at the time of Alice, we are maximizing aliceCurrentPick - (bobNextPick onwards), which will inherently minimize bobNextPick. At Bob's turn in recursion, we are again taking maximum of two options, because that will be negated on a layer above, hence playing the optimal move to reduce the difference.
*/ 
class Solution {
public:
    int go (int i, int j, vector<int>& stones, vector<vector<int>>& dp, int sum) {
        if (i == j) return 0;
        if (dp[i][j] > -1) return dp[i][j];
        dp[i][j] = max(sum-stones[i]-go(i+1,j,stones,dp,sum-stones[i]), sum-stones[j]-go(i, j-1, stones, dp,sum-stones[j]));
        return dp[i][j];
    }
    int stoneGameVII(vector<int>& stones) {
        vector<vector<int>>dp(stones.size(), vector<int>(stones.size(),-1));
        int sum = 0;
        for (int i : stones) sum+=i;
        return go (0, stones.size()-1, stones, dp, sum);
    }
};
