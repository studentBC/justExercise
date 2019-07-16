/*
 * There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:
[[5,8,6],[19,14,13],[7,5,12],[14,15,17],[3,20,10]]
Input: [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
             Minimum cost: 2 + 5 + 3 = 10.

 */
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>>dp(costs.size()+1,vector<int>(3,0));
        for (int i = 1; i <= costs.size(); ++i) {
            dp[i][0] = min(dp[i-1][1]+costs[i-1][0], dp[i-1][2]+costs[i-1][0]);
            dp[i][1] = min(dp[i-1][0]+costs[i-1][1], dp[i-1][2]+costs[i-1][1]);
            dp[i][2] = min(dp[i-1][0]+costs[i-1][2], dp[i-1][1]+costs[i-1][2]);
        }
        return min (dp.back()[0], min(dp.back()[1], dp.back()[2]));
    }
};
//the fatest method
class Solution
{
public:
    int minCost(vector<vector<int>>& costs)
    {
        int nHouses = costs.size();
        int prevRed = 0;
        int prevGreen = 0;
        int prevBlue = 0;
        
        for(int i = nHouses - 1; i >= 0; i--)
        {
            int red = costs[i][0] + min(prevGreen, prevBlue);
            int green = costs[i][1] + min(prevRed, prevBlue);
            int blue = costs[i][2] + min(prevRed, prevGreen);
            
            prevRed = red;
            prevGreen = green;
            prevBlue = blue;
        }
        
        return min(prevRed, min(prevGreen, prevBlue));
    }
};
