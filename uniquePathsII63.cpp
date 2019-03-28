class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<long long>>path(obstacleGrid.size(),vector<long long>(obstacleGrid[0].size(),-1));
        int row = obstacleGrid.size()-1, col = obstacleGrid[0].size()-1;
        bool continuous = true;
        for (int i = row; i > -1; i--) {
            if (obstacleGrid[i][col] == 0 && continuous) {
                path[i][col] = 1;
            } else {
                path[i][col] = 0;
                continuous = false;
            }
        }
        continuous = true;
        for (int i = col; i > -1; --i) {
            if (obstacleGrid[row][i] == 0 && continuous) {
                path[row][i] = 1;
            } else {
                path[row][i] = 0;
                continuous = false;
            }
        }
        for (int i = col-1; i > -1; --i) {
            for (int j = row-1; j > -1; --j) {
                if (obstacleGrid[j][i] == 0) {
                    path[j][i] = path[j+1][i] + path[j][i+1];
                } else {
                    path[j][i] = 0;
                }   
            }
        }
        /*
        for (int i = 0; i < path.size(); i++) {
            for (int j = 0; j < path[i].size(); j++) {
                cout << path[i][j] << " , ";
            }   
            cout << endl;
        }
        */
        return path[0][0];
    }
};  

