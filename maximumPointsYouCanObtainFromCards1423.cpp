class Solution {
public:
    vector<int>dpf, dpb;
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size(), ans = 0;
        dpf = vector<int>(len+1,  -1);
        dpb = vector<int>(len+1, -1);
        dpf[0] = dpb[0] = 0;
        for (int i = 0; i < len; i++) {
            dpf[i+1] = dpf[i]+cardPoints[i];
            dpb[i+1] = dpb[i]+cardPoints[len-i-1];
        }
        for (int i = 0; i <= k; i++) {
            ans = max(ans, dpf[i]+dpb[k-i]);
        }
        return ans;
    }
};
//my MLE dp solution
class Solution {
public:
    vector<vector<int>>dp;
    int go (int left, int right, vector<int>& cardPoints, int k) {
        if (dp[left][right] > -1) return dp[left][right];
        if (left == right) return cardPoints[left];
        if (k == 0) return max(cardPoints[left], cardPoints[right]);
        return dp[left][right] = 
            max(go(left+1, right, cardPoints, k-1)+cardPoints[left],
             go(left, right-1, cardPoints, k-1)+cardPoints[right]);
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        dp = vector<vector<int>>(len, vector<int>(len, -1));
        return go(0, len-1, cardPoints, k-1);    
    }
};
