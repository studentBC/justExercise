//https://leetcode.com/problems/maximum-matrix-sum/discuss/1417606/C%2B%2B-The-basic-idea-is-to-eliminate-negative-signs
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negative = 0, row = matrix.size(), col = matrix[0].size(), small = INT_MAX;
        long long ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] < 0) {
                    negative++;
                    small = min(small, -matrix[i][j]);
                    ans-=matrix[i][j];
                } else {
                    small = min(small, matrix[i][j]);
                    ans+=matrix[i][j];
                }
            }
        }
        //cout << small << endl;
        small<<=1;
        if (negative%2) return ans-small;
        else return ans;
    }
};
