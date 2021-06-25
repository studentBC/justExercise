class Solution {
public:
    int b, t, ans = INT_MIN;
    void go (int cost, int ti, vector<int>& toppingCosts) {
        if( abs(cost) < abs(ans) || abs(cost) == abs(ans) && cost > ans) ans = cost;
        if (cost <= 0 || ti >= t) return;
        go (cost, ti+1, toppingCosts);
        go (cost-toppingCosts[ti], ti+1, toppingCosts);
        go (cost-toppingCosts[ti]*2, ti+1, toppingCosts);
        
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        b = baseCosts.size(); t = toppingCosts.size();
        ans = target-baseCosts[0];
        for (int i = 0; i < b; i++) {
            go (target-baseCosts[i], 0, toppingCosts);
        }
        return target-ans;
    }
};
