class Solution {
public:
    int row , col;
    int step[5] = {-1,0,1,0,-1};
    
    void go (int i, int j, int mark, vector<vector<int>>& grid, vector<pair<int, int>>& record) {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j]!=1) return;
        grid[i][j] = mark;
        record.push_back({i, j});
        for (int a = 0; a < 4; a++) {
            go (i+step[a], j +step[a+1], mark, grid, record);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        vector<pair<int, int>>one, two;
        for (int i = 0, k = 2; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    if (k == 2) go (i, j, k, grid, one);
                    else go (i, j, k, grid, two);
                    k++;
                }
            }
        }
        int ans = INT_MAX, len = 0;
        for (int i = 0; i < one.size(); i++) {
            for (int j = 0; j < two.size(); j++) {
                len = abs(one[i].first-two[j].first) + abs(one[i].second-two[j].second);
                ans = min(ans, len);
            }
        }
        return ans-1;
    }
};
