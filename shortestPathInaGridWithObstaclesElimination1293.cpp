class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<tuple<int,int,int,int>>pos;
        vector<vector<vector<bool>>>visited(k+1 , vector<vector<bool>>(grid.size(),   vector<bool>(grid[0].size(), false)));
        int direct[]={1,0,-1,0,1};
        int x, y, left, step, ex = grid.size()-1, ey = grid[0].size()-1, ans = INT_MAX, total, answer = 0;
        pos.push(make_tuple(0,0,0,0));
        visited[0][0][0] = true;
        while (!pos.empty()) {
            total = pos.size();
            for (int i = 0; i < total; i++) {
                tuple<int,int,int,int>move = pos.front();
                pos.pop();
                left = get<2>(move);
                step = get<3>(move);
                //cout << get<0>(move) <<" , " << get<1>(move) <<" -> ";
                if (ex == get<0>(move) && ey == get<1>(move)) {
                    ans = min (step, ans);
                    if (ans == ex+ey) return ans;
                    return answer;
                }

                //visited[left][get<0>(move)][get<1>(move)] = true;
                for (int j = 0; j < 4; j++) {
                    x = get<0>(move)+direct[j];
                    y = get<1>(move)+direct[j+1];
                    left = get<2>(move);
                    if (x > -1 && x < grid.size() && y > -1 && y < grid[0].size()) {
                        if (grid[x][y]) left++;
                        if (left <= k && !visited[left][x][y]) {
                            visited[left][x][y] = true;
                            pos.push(make_tuple(x,y,left,step+1));
                        }
                    }
                }
            }
            answer++;
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (k >= m + n - 3) {
            return m + n - 2;
        }
        const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        priority_queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        vector<vector<int>> v(m, vector<int>(n, -1));
        while (!q.empty()) {
            int step = q.top().first;
            int x = q.top().second >> 18;
            int y = (q.top().second >> 12) & 63;
            int z = q.top().second & 4095;
            q.pop();
            if (v[x][y] >= 0 && v[x][y] <= z) {
                continue;
            }
            if (x == m - 1 && y == n - 1) {
                return -step;
            }
            v[x][y] = z;
            for (int i = 0; i < 4; ++i) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
                    int zz = z + grid[xx][yy];
                    if (zz <= k) {
                        q.push(make_pair(step - 1, (xx << 18) | (yy << 12) | zz));
                    }
                }
            }
            
        }
        return -1;
    }
};
