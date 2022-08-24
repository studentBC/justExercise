class Solution {
public:
    int step[5] = {-1, 0, 1, 0, -1};
    int swimInWater(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>>pos;
        int ans = INT_MAX, x, y, h, row = grid.size(), col = grid[0].size(), xx, yy, hh;
        vector<vector<int>>beenTo(row, vector<int>(col, INT_MAX));
        int c = 0;
        pos.push({0, 0, grid[0][0]});
        while (!pos.empty()) {
            x = get<0>(pos.front());
            y = get<1>(pos.front());
            h = get<2>(pos.front());
            pos.pop();
            if (x+1 == row && y+1 == col) {
                ans = min(ans, h);
                continue;
            }
            
            for (int i = 0; i < 4; i++) {
                xx = x + step[i];
                yy = y + step[i+1];
                
                if (xx > -1 && xx < row && yy > -1 && yy < col) {
                    hh = max(h, grid[xx][yy]);
                    
                    if (hh < beenTo[xx][yy]) {
                        beenTo[xx][yy] = hh;
                        pos.push({xx, yy, hh});
                    }
                }
            }
        }
        return ans;
    }
};
//beat 51%
class Solution {
public:
    struct T {
        int t, x, y;
        T(int a, int b, int c) : t (a), x (b), y (c){}
        bool operator< (const T &d) const {return t > d.t;}
    };
    int step[5] = {-1, 0, 1, 0, -1};
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<T>pos;
        int ans = 0, x, y, h, row = grid.size(), col = grid[0].size(), xx, yy, next, hh;
        vector<vector<bool>>beenTo(row, vector<bool>(col, false));
        
        pos.push({grid[0][0], 0, 0});
        //int c = 0;
        while (!pos.empty()) {
            h = pos.top().t;
            x = pos.top().x;
            y = pos.top().y;
            //cout << x << ", " << y <<" : " << h << endl ;
            pos.pop();
            beenTo[x][y] = true;
            ans = max(ans, h);
            if (x+1 == row && y+1 == col) {  
                return ans;
            }
            
            //beenTo[x][y] = min(h, beenTo[x][y]);
            hh = INT_MAX;
            for (int i = 0; i < 4; i++) {
                xx = x + step[i];
                yy = y + step[i+1];
                if (xx > -1 && xx < row && yy > -1 && yy < col && !beenTo[xx][yy]) {
                    pos.push(T(grid[xx][yy], xx, yy));
                }
                //if (hh < beenTo[xx][yy]) pos.push({xx, yy, hh});
            }
        }
        return ans;
    }
};
