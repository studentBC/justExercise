class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size()<3)return 0;
        vector<int>diff;
        for (int i = 1; i < A.size(); i++) {
            diff.push_back(A[i]-A[i-1]);
        }
        int prev = diff[0], count = 2, upper, ans = 0;
        for (int i = 1; i < diff.size(); i++) {
            if (prev == diff[i]) {
                count++;
            } else {
                if (count > 2) {
                    upper = (count-3+1);
                    if (upper > 1) {
                        ans+=(upper+1)*upper/2;
                    } else {
                        ans++;
                    }
                }
                count = 2;
            }
            prev = diff[i];
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3)
            return 0;
        vector<int> dp(n, 0);
        if (A[1] - A[0] == A[2] - A[1])
            dp[2] = 1;
        for (int i = 3; i < n; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                dp[i] = dp[i - 1] + 1;
        }
        
        int res = 0;
        for (int i = 2; i < n; i++)
            res += dp[i];
        return res;
    }
};
