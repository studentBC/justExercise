class Solution {
public:
    int check (int start, int end, vector<int>& A) {
        int bought = INT_MAX;
        int profit = 0, max_profit = 0;
        for (int i = start; i < end; i++){
            bought = A[i] < bought ? A[i]: bought;
            profit = A[i] - bought;
            max_profit = profit > max_profit ? profit : max_profit;
        }
        return max_profit;
    }
    int maxProfit(vector<int>& prices) {
        int ans = 0, sum;
        for (int i = 1; i < prices.size(); i++) {
            sum = check(0,i+1,prices);
            sum += check(i,prices.size(),prices);
            ans = max (ans,sum);
        }
        return ans;
    }
};
//the fatest method
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        vector<vector<int>> states(2, vector<int>({INT_MIN, 0, INT_MIN, 0}));
        int cur = 0, next = 1;
        for(int i = 0; i < prices.size(); i++)
        {
            states[next][0] = max(states[cur][0], -prices[i]);
            states[next][1] = max(states[cur][1], states[cur][0] + prices[i]);
            states[next][2] = max(states[cur][2], states[cur][1] - prices[i]);
            states[next][3] = max(states[cur][3], states[cur][2] + prices[i]);
            swap(cur, next);
        }
        return max(states[cur][1], states[cur][3]);
    }
};
/*
The thinking is simple and is inspired by the best solution from Single Number II (I read through the discussion after I use DP).
Assume we only have 0 money at first;
4 Variables to maintain some interested 'ceilings' so far:
The maximum of if we've just buy 1st stock, if we've just sold 1nd stock, if we've just buy 2nd stock, if we've just sold 2nd stock.
Very simple code too and work well. I have to say the logic is simple than those in Single Number II.
*/
public class Solution {
    public int maxProfit(int[] prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(int i:prices){                              // Assume we only have 0 money at first
            release2 = Math.max(release2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
            hold2    = Math.max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
            release1 = Math.max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold1    = Math.max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
        }
        return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.
    }
};
//use cpp implement 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(int i:prices){                              // Assume we only have 0 money at first
            hold1    = max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
            release1 = max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold2    = max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
            release2 = max(release2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
        }
        return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.

    }
};
