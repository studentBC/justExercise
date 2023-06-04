class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool>row(n, 1), col(n, 1);
        long long ans = 0, r = n, c = n;
        for (int i = queries.size()-1; i > -1; i--) {
            if (queries[i][0] == 0 && row[queries[i][1]]) {
                ans+=c*queries[i][2];
                row[queries[i][1]] = false;
                r--;
            }
            if (queries[i][0] && col[queries[i][1]]) {
                ans+=r*queries[i][2];
                col[queries[i][1]] = false;
                c--;
            }
        }
        return ans;
    }
};
