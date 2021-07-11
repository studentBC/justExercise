class Solution {
public:
    int ans = INT_MAX, len, length, oi, oj;
    int step[5] = {1,0,-1,0,1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        len = maze.size(); length = maze[0].size();
        oi = entrance[0]; oj = entrance[1];
        queue<tuple<int, int, int>>path;
        vector<vector<int>>visited(len, vector<int>(length, false));
        path.push(make_tuple(oi, oj, 0));
        int i, j, sp, x, y, c = 1, pl = 0;
        
        while (!path.empty()) {
            pl = path.size();
            for (int k = 0; k < pl; k++) {
                tuple pos = path.front();
                path.pop();
                //cout << get<0>(pos) <<" , " << get<1>(pos) << endl;
                x = get<0>(pos);
                y = get<1>(pos);
                sp = get<2>(pos)+1;
                for (int a = 0; a < 4; a++) {
                    i=x+step[a]; j=y+step[a+1];
                    if (i < 0 || j < 0 || i >= len || j >= length || maze[i][j] == '+') continue;
                    if (i == 0 || j == 0 || i == len-1 || j == length -1) {
                        if (!(oi == i && oj == j)) {
                            return c;
                        }
                        continue;
                    }
                    maze[i][j] = '+';
                    path.push({i, j, sp});
                }
            }
            c++;
        }
        //cout << c <<" , ";
        return ans == INT_MAX?-1:ans;
    }
};
