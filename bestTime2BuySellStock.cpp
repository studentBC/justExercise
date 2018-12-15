class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, profit;
        for (int i = prices.size()-1; i > -1 ; i--) {
            for (int j = 0; j < i; j++) {
                profit = prices[i] - prices[j];
                if (profit > max) max = profit;
            }
        }
        return max;
    }
};
//fatest method
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought = INT_MAX;
        int profit = 0, max_profit = 0;
        for (int v: prices){
            bought = v < bought ? v: bought;
            profit = v - bought;
            max_profit = profit > max_profit ? profit : max_profit;
        }
        return max_profit;
    }
};
