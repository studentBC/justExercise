/*
You are given a m x n 2D grid initialized with these three possible values.

    -1 - A wall or an obstacle.
    0 - A gate.
    INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.

Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF

After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

wrong test case:
[[0,0,0,0,2147483647,2147483647],[-1,0,-1,2147483647,0,-1],[-1,-1,0,0,2147483647,0],[-1,-1,2147483647,2147483647,2147483647,-1],[2147483647,2147483647,-1,2147483647,-1,2147483647],[2147483647,2147483647,0,-1,-1,0],[0,0,0,2147483647,-1,0],[0,-1,0,-1,0,0],[2147483647,0,-1,-1,2147483647,2147483647],[0,0,-1,-1,-1,2147483647]]
*/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<pair<int,int>>pos, temp;
        for(int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] == 0) {
                    pos.emplace_back(pair<int,int>(i,j));
                }
            }
        }
        int i,j;
        while (!pos.empty()) {
        	while (!pos.empty()) {
				i = pos.back().first;
				j = pos.back().second;
				if (i+1 < rooms.size()) {
					if (rooms[i+1][j] > rooms[i][j]+1) {
						rooms[i+1][j] = rooms[i][j]+1;
						temp.emplace_back(make_pair(i+1,j));
					}
				}
				if (i > 0) {
					if (rooms[i-1][j] > rooms[i][j]+1) {
						rooms[i-1][j] = rooms[i][j]+1;
						temp.emplace_back(make_pair(i-1,j));
					}
				}
				if (j+1 < rooms[0].size()) {
					if (rooms[i][j+1] > rooms[i][j]+1) {
						rooms[i][j+1] = rooms[i][j]+1;
						temp.emplace_back(make_pair(i,j+1));
					}
				}
				if (j > 0) {
					if (rooms[i][j-1] > rooms[i][j]+1) {
						rooms[i][j-1] = rooms[i][j]+1;
						temp.emplace_back(make_pair(i,j-1));
					}
				}
				pos.pop_back();
			}
			pos = temp;	
        }
        return;
    }
};
//the fatest method
class Solution {
    public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        for(int i=0;i<rooms.size();i++) {
            for(int j=0;j<rooms[0].size();j++) {
                if(rooms[i][j] == 0) {
                    q.push(make_pair(i, j));
                }
            }
        }
        vector<pair<int, int>> dir(4);
        dir[0] = make_pair(0, 1);
        dir[1] = make_pair(0, -1);
        dir[2] = make_pair(1, 0);
        dir[3] = make_pair(-1, 0);

        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            
            for(int i=0;i<4;i++) {
                int h = p.first + dir[i].first;
                int r = p.second + dir[i].second;
                
                if(h<0 || h>=rooms.size() || r<0 || r>=rooms[0].size() || rooms[h][r] != INT_MAX)
                    continue;
                
                rooms[h][r] = rooms[p.first][p.second]+1;
                q.push(make_pair(h, r));
            }
        }
    }
};
