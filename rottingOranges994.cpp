class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>rotten;
        int good = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    rotten.push(pair<int,int>(i,j));
                } else if (grid[i][j] == 1) {
                    good++;
                }
            }
        }
        int count = 0, rot;
        pair<int,int>location;
        bool found = false;
        while (!rotten.empty()) {
            rot = rotten.size();
            found = false;
            //cout << rot << " count: " << count << endl;
            for (int i = 0; i < rot; i++) {
                location = rotten.front();
                rotten.pop();
                //cout <<location.first << " , " << location.second << endl;
                //up
                if (location.first > 0 && grid[location.first-1][location.second] == 1) {
                    grid[location.first-1][location.second] = 2;
                    rotten.push(pair<int,int>(location.first-1, location.second));
                    good--;found = true;
                }
                if (location.first+1 < grid.size() && grid[location.first+1][location.second] == 1) {
                    grid[location.first+1][location.second] = 2;
                    rotten.push(pair<int,int>(location.first+1, location.second));
                    good--;found = true;
                }
                if (location.second+1 < grid[0].size() && grid[location.first][location.second+1] == 1) {
                    grid[location.first][location.second+1] = 2;
                    rotten.push(pair<int,int>(location.first, location.second+1));
                    good--;found = true;
                }
                if (location.second >0 && grid[location.first][location.second-1] == 1) {
                    grid[location.first][location.second-1] = 2;
                    rotten.push(pair<int,int>(location.first, location.second-1));
                    good--;found = true;
                }
            }
            if (found)count++;
            //cout << count << endl;
        }
        if (good == 0) return count;
        return -1;
    }
};

