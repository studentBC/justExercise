class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int ans = INT_MAX, row = grid.size(), col = grid[0].size(), x, y, xx, yy, dist;
        int step[5] = {-1, 0, 1, 0, -1};
        queue<tuple<int, int, int>>pos;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '*') {
                    pos.push({i, j, 0});
                    break;
                }
            }
            if (!pos.empty()) break;
        }
        while (!pos.empty()) {
            x = get<0>(pos.front());
            y = get<1>(pos.front());
            dist = get<2>(pos.front());
            pos.pop();
            if (grid[x][y] == '#') return  dist;
            else if (grid[x][y] == 'X') continue;
            grid[x][y] = 'X';
            
            for (int i = 0; i < 4; i++) {
                xx = x+step[i];
                yy = y+step[i+1];
                if (xx > -1 && xx < row && yy > -1 && yy < col && 
                   grid[xx][yy] != 'X') {
                    pos.push({xx, yy, dist+1});
                }
            }
        }
        return -1;
    }
};
