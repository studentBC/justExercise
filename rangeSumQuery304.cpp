class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int sum = 0;
        map = matrix;
        for (int i = 0; i < matrix.size(); i++) {
            sum = 0;
            for (int j = 0; j < matrix[i].size(); j++) {
                sum+=matrix[i][j];
                map[i][j] = sum;
            }
        }
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum +=(map[i][col2] - map[i][col1-1]);    
        }
        return sum;
    }
private:
    vector<vector<int>> map;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
//second fatest method
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int m = 0, n = 0;
        if (!matrix.empty() && !matrix[0].empty()) {
            m = matrix.size();
            n = matrix[0].size();
        }
        sums.resize(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sums[i+1][j+1] = sums[i][j+1] + sums[i+1][j] - sums[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] + sums[row1][col1] - sums[row1][col2+1] - sums[row2+1][col1];
    }
    
private:
    vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
