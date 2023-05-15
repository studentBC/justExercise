int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> dirs = {{0, 1}, {1, 1}, {-1, 1}};
    vector<vector<int>> cache(m, vector<int>(n, -1));

    function<int(int, int)> dp = [&](int i, int j) {
        if (cache[i][j] != -1) return cache[i][j];
        int ans = 0;
        for (auto [x, y] : dirs) {
            int ni = i + x, nj = j + y;
            if (ni >= 0 && ni < m && nj < n && grid[i][j] < grid[ni][nj])
                ans = max(ans, 1 + dp(ni, nj));
        }
        return cache[i][j] = ans;
    };
    int res = 0;
    for (int i = 0; i < m; i++)
        res = max(res, dp(i, 0));
    return res;
}
//66 ms solution
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); 
        queue<pair<int, int>> q; 
        for (int i = 0; i < m; ++i) {
            q.emplace(i, 0); 
            grid[i][0] *= -1; 
        }
        int ans = -1; 
        while (q.size()) {
            for (int sz = q.size(); sz; --sz) {
                auto [i, j] = q.front(); q.pop(); 
                for (int ii = i-1, jj = j+1; ii <= i+1; ++ii) 
                    if (0 <= ii && ii < m && 0 <= jj && jj < n && -grid[i][j] < grid[ii][jj]) {
                        q.emplace(ii, jj); 
                        grid[ii][jj] *= -1; 
                    }
            }
            ++ans; 
        }
        return max(0, ans); 
    }
};
