class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int last = n*n, num = 1, up = 0, down = n-1, right = n-1, left = 0;
        vector<vector<int>>ans(n,vector<int>(n,-1));
        while (num <= last) {
            for (int i = 0; i < n; i++) {
                if (ans[up][i] < 0) {
                    ans[up][i] = num;
                    num++;
                }
            }   
            up++;
            for (int i = 0; i < n; i++) {
                if (ans[i][right] < 0) {
                    ans[i][right] = num;
                    num++;
                }
            }
            right--;
            for (int i = n-1; i > -1; i--) {
                if (ans[down][i] < 0) {
                    ans[down][i] = num;
                    num++;
                }
            }
            down--;
            for (int i = n-1; i > -1; i--) {
                if (ans[i][left] < 0) {
                    ans[i][left] = num;
                    num++;
                }
            }
            left++;
        }
        return ans;
    }
};

