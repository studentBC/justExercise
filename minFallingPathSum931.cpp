class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int ans = INT_MAX;
        vector<vector<int>>temp(A.size());
        for (int i = 0; i < A.size(); i++) {
            temp[i] = vector<int>(A[i].size());
        }   
        bool first = true;
        int mini;
        for (int i = A.size()-1; i > -1 ; i--) {
            for (int j = 0; j < A[i].size(); j++) {
                if (first) {
                    temp[i][j] = A[i][j];
                } else {
                    if (j == 0) {
                        temp[i][j] = min(temp[i+1][j],temp[i+1][j+1]) + A[i][j];
                    } else if (j == A[i].size()-1) {
                        temp[i][j] = min(temp[i+1][j],temp[i+1][j-1]) + A[i][j];
                    } else { 
                        mini = min(temp[i+1][j],temp[i+1][j-1]);
                        temp[i][j] = min(mini, temp[i+1][j+1]) + A[i][j];
                    }
                }
                //cout << "( " << i <<" , " << j <<" ) : " << temp[i][j] << endl;
            }
            first = false;
        }
        for (int i = 0; i < A[0].size(); i++) {
            if (ans > temp[0][i]) ans = temp[0][i];
        }
        return ans;
    }
};
//the fatest method
static const auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> &dp = A;
        int n = dp.size();
        if(n == 0)  return 0;
        if(n == 1)  return dp[0][0];
        for(int i = 1; i < n; ++i)
            for(int j = 0; j < n; ++j){
                int mmin = dp[i-1][j];
                if(j)  mmin = min(mmin, dp[i-1][j-1]);
                if(j + 1 < n)  mmin = min(mmin, dp[i-1][j+1]);
                dp[i][j] += mmin;
            }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
