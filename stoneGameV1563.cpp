class Solution {
public:
    int len;
    vector<int>sum;
    vector<vector<int>>dp;
    int go (int left, int right, vector<int>& stoneValue) {
        if (left >= right) return 0;
        else if (dp[left][right] > -1) return dp[left][right];
        int ls, rs, ans;
        for (int i = left; i <= right; i++) {
            if (left == 0) ls = sum[i];
            else ls = sum[i]-sum[left-1];
            rs = sum[right]-sum[i];
            if (ls < rs) {
                ans = ls + go(left, i, stoneValue);
            } else if (ls == rs) { //keep resursively finding
                ans = ls + max(go(left,i,stoneValue), go(i+1, right, stoneValue));
            } else {
                ans = rs + go(i+1, right, stoneValue);
            }
            dp[left][right] = max(ans, dp[left][right]);
        }
        return dp[left][right];
    }
    int stoneGameV(vector<int>& stoneValue) {
        int s = 0;
        len = stoneValue.size();
        dp = vector<vector<int>>(len, vector<int>(len, -1));
        for (int i = 0; i < len; i++) {
            s+=stoneValue[i];
            sum.push_back(s);
        }
        return go (0, len-1, stoneValue);
    }
};
//44 ms solution
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        if (n <= 1)
            return 0;
        
        vector<int> sum(n);
        for(int i = 0; i < n; i++)
            sum[i] = stoneValue[i] + (i>=1?sum[i-1]:0);

        return find(stoneValue, sum, dp, 0, n-1);
    }
    
private:
    int find(vector<int> &stoneValue, vector<int> &sum, vector<vector<int>> &dp, int s, int e)
    {
        if (e-s+1<=1)
            return 0;
        if (dp[s][e] >= 0)
            return dp[s][e];
        
        int rangesum = sum[e] - sum[s] + stoneValue[s];
        int lsum = 0, maxFound = 0;
        for(int le = s; le < e; le++) {
            lsum += stoneValue[le];
            int rsum = rangesum - lsum;
            if (lsum < rsum){
                if (lsum*2 > maxFound)
                    maxFound = max(maxFound, lsum + find(stoneValue, sum, dp, s, le));
            }
            else if (lsum > rsum){
                if (rsum*2 > maxFound)
                    maxFound = max(maxFound, rsum + find(stoneValue, sum, dp, le+1, e));
            }
            else{
                if (lsum*2 > maxFound)
                    maxFound = max(maxFound, lsum + max(find(stoneValue, sum, dp, s, le), find(stoneValue, sum, dp, le+1, e)));
            }
        }
        
        return dp[s][e] = maxFound;
    }
};
