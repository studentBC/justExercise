class Solution {
public:
    int step[5] = {-1, 0, 1, 0, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), x, y, len, ans = 0, count = 0;
        queue<pair<int, int>>next;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    //grid[i][j] = 1;
                    next.push({i,j});
                    //count++;
                } else if (grid[i][j] == 1) count++;
            }
        }
        if (next.empty()) {
            if (count) return -1;
            else return 0;
        }
        while (!next.empty()) {
            len = next.size();
            //cout <<endl<< len << endl;
            ans++;
            for (int j = 0; j < len; j++) {
                if (grid[next.front().first][next.front().second] == 99) count--;
                //cout << next.front().first<<", " << next.front().second << endl;
                grid[next.front().first][next.front().second] = 2;
                //cout << next.front().first <<", " <<next.front().second<<endl;
                for (int i = 0; i < 4; i++) {
                    x = next.front().first+step[i];
                    y = next.front().second+step[i+1];
                    if (x > -1 && x < row && y > -1 && y < col && grid[x][y] == 1) {
                        grid[x][y] = 99;
                        next.push({x, y});
                    }
                }
                next.pop();
            }
        }
        return count > 0?-1:ans-1;
    }
};
