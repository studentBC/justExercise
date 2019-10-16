/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:

Input: [[1,5,3],[2,9,4]]
Output: 5
Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
             Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5. 

wrong test case:
[[8,16,12,18,9],[19,18,8,2,8],[8,5,5,13,4],[15,9,3,19,2],[8,7,1,8,17],[8,2,8,15,5],[8,17,1,15,3],[8,8,5,5,16],[2,2,18,2,9]]
*/
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        vector<vector<int>>dp (costs.size(), vector<int>(costs[0].size(), INT_MAX));
        for (int i = 0; i < costs[0].size(); i++)dp[0][i] = costs[0][i];
        int cheap = INT_MAX, sum, ans = INT_MAX, index;
        for (int i = 1; i < costs.size(); i++) {
            for (int j = 0; j < costs[i-1].size(); j++) {
                cheap = INT_MAX;
                for (int k = 0; k < costs[0].size(); k++) {
                    if (k!=j) cheap = min (cheap, dp[i-1][k]);
                }
                dp[i][j] = costs[i][j]+cheap;
            }
        }

        for (int i = 0; i < costs[0].size(); i++) ans = min (dp.back()[i], ans);
        return ans;
    }
};
//4ms solution
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;
        int k = costs[0].size(); 
        vector<vector<int>> dp(n, vector<int>(k, 0));
        for(int i = 0;i<k;i++){
            dp[0][i] = costs[0][i];
        }
        int first = 0, second = 0, first_idx = 0;
        for(int i = 1;i<n;i++){
            first = INT_MAX; second = INT_MAX, first_idx = 0;
            for(int j = 0;j<k;j++){
                if(dp[i-1][j] <= first){
                    second = first;
                    first = dp[i-1][j];
                    first_idx = j;
                }
                else if(dp[i-1][j] < second){
                    second = dp[i-1][j];
                }
            }
            if(first == second) first_idx = -1;
            // cout << first << second << endl;
            for(int j = 0;j<k;j++){
                if(j == first_idx)
                    dp[i][j] = second + costs[i][j];
                else
                    dp[i][j] = first + costs[i][j];
            }
        }
        first = INT_MAX;
        for(int j = 0;j<k;j++){
            if(dp[n-1][j] < first){
                first = dp[n-1][j];
            }
        }
        return first;
    }
};
