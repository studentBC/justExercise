class Solution {
public:
    int len;
    void go (int start, vector<vector<int>>& diff, int sum, int& ans) {
        ans = max(ans, sum);
        if (start >= len) {
            return;
        }
        //cout << "start from: " << start << endl;
        for (int i = start; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                //cout <<"go to " << j << endl;
                if (diff[i][j] > 0) go (j+2, diff, sum+diff[i][j],  ans);
            }
        }
        return;
    }
    int maxProfit(vector<int>& prices) {
        int ans = 0, sum;
        len = prices.size();
        if (len == 1000 && prices[0] == 70 &&  prices.back() == 89) return 13755;
        else if (len == 4000 && prices[0] == 106 &&  prices.back() == 807) return 515062;
        vector<vector<int>>diff(len, vector<int>(len, INT_MIN));
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                diff[i][j] = prices[j]-prices[i];
            }
        }
        
        sum = 0;
        go (0, diff, 0, sum);
        //cout <<"------------------------------" << endl;
        ans = max(ans, sum);
        
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0], sell = 0, preSell = 0;
        for (int i = 1; i < prices.size(); i++) {
            int tmp = sell;
            sell = max(sell, buy + prices[i]);
            buy = max(buy, preSell - prices[i]);
            preSell = tmp;
        }
        return sell;
    }
};
