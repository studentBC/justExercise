class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int step = 0;
        vector<int>mi(n), mj(m);

        vector<pair<int, int>> q, q1;
        q.push_back({0, 0});

        while (!q.empty()) {
            step++;
            for (auto[i, j]: q) {
                if (i == m-1 && j == n-1) return step;
                for (int a = max(mi[j], i)+1; a < m && a-i<=grid[i][j]; a++) q1.push_back({a, j});
                for (int a = max(mj[i], j)+1; a < n && a-j <= grid[i][j]; a++) q1.push_back({i, a});
                mi[j] = max(mi[j], i+grid[i][j]);
                mj[i] = max(mj[i], j+grid[i][j]);
            }
            swap(q, q1);
            q1.clear();
        }

        return -1;
    }
};
