class Solution {
public:
    int findW (int start, vector<char>row) {
        int count = 0;
        for (int i = start; i < row.size(); i++) {
            if (row[i] == '1') {
                count++;
            } else {
                break;
            }
        }
        return count;
    }
    int findL (int i, int j, int end, vector<vector<char>>& matrix) {
        int count = 1;
        for (int a = i+1; a < matrix.size(); a++) {
            for (int b = j; b <= end; b++) {
                if (matrix[a][b] == '0') return count;
            }
            count++;
        }
        return count;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int width , length, max = 0, square;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    width = findW(j, matrix[i]);
                    for (int k = 0; k < width; k++) {
                        length = findL(i, j, j+k, matrix);
                        //cout << " ( " << i << " , " << j << " ) width: " << k << "  length: " << length << endl;
                        square = (k+1 < length)?k+1:length;
                        square*=square;
                        if (max < square) max = square;
                    }
                }
            }
        }
        return max;
    }

};
//the fatest method
#pragma GCC optimize ("O3")
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size(), ans = 0;
        int dp[n][m] = {0};
        for(int i(0); i<n; i++)
        {
            dp[i][0] = matrix[i][0] - '0';
            if(ans < dp[i][0]) ans = dp[i][0];
        }
        for(int i(0); i<m; i++)
        {
            dp[0][i] = matrix[0][i] - '0';
            if(ans < dp[0][i]) ans = dp[0][i];
        }
        
        for(int i(1); i<n; i++)
        {
            for(int j(1); j<m; j++)
            {
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                if(dp[i][j] > ans) ans = dp[i][j];
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        return ans*ans;
    }
};
