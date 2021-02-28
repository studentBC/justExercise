class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>>ans(isWater.size(), vector<int>(isWater[0].size(), INT_MAX));
        queue<pair<int,int>>pos;
        for (int i = 0; i < isWater.size(); i++) {
            for (int j = 0; j < isWater[i].size(); j++) {
                if (isWater[i][j]) {
                    ans[i][j] = 0;
                    pos.push(make_pair(i, j));
                }
            }
        }
        int v, i, j;
        while (!pos.empty()) {
            i = pos.front().first;
            j = pos.front().second;
            v = ans[i][j];
            pos.pop();
            if (i && ans[i-1][j] == INT_MAX) {
                ans[i-1][j] = v+1;
                pos.push(make_pair(i-1,j));
            }
            if (j && ans[i][j-1] == INT_MAX) {
                ans[i][j-1] = v+1;
                pos.push(make_pair(i,j-1));
            }
            if (i+1 < isWater.size() && ans[i+1][j] == INT_MAX) {
                ans[i+1][j] = v+1;
                pos.push(make_pair(i+1,j));
            }
            if (j+1 < isWater[0].size() && ans[i][j+1] == INT_MAX) {
                ans[i][j+1] = v+1;
                pos.push(make_pair(i,j+1));
            }
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size(), c = isWater[0].size();
        vector<vector<int>> ans(r, vector<int>(c, -1));

        vector<pair<int, int>> queue;

        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++)
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    queue.push_back(make_pair(i, j));
                }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int head=0; head<queue.size(); head++) {
            int x = queue[head].first, y = queue[head].second;
            int d = ans[x][y];

            for (int k=0; k<4; k++) {
                int xx = x + dx[k], yy = y + dy[k];
                if (xx >= 0 && xx < r && yy >= 0 && yy < c && ans[xx][yy] == -1) {
                    ans[xx][yy] = d + 1;
                    queue.push_back(make_pair(xx, yy));
                }
            }
        }
        return ans;
    }
};

