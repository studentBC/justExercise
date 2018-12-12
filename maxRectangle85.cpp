class Solution {
public:
	int findW (int start, vector<char>row) {
        int count = 0;
        for (int i = start; i < row.size(); i++) {
            if (row[i] == '1') {
                count++;
            } else {
                break;
            }
        }
        return count;
    }
    int findL (int i, int j, int end, vector<vector<char>>& matrix) {
        int count = 1;
        for (int a = i+1; a < matrix.size(); a++) {
            for (int b = j; b <= end; b++) {
                if (matrix[a][b] == '0') return count;
            }
            count++;
        }
        return count;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int width , length, max = 0, rect;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    width = findW(j, matrix[i]);
                    for (int k = 0; k < width; k++) {
                        length = findL(i, j, j+k, matrix);
                        //cout << " ( " << i << " , " << j << " ) width: " << k << "  length: " << length << endl;
                        rect = (k+1)*length;
                        if (max < rect) max = rect;
                    }
                }
            }
        }
        return max;
    }
};
//fatest method
static const auto speedup = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        if (m == 0 || n == 0) return 0;

        vector<vector<int>> heights(m, vector<int>(n + 2, 0));
        for (int j = 0; j < n; ++j)
            heights[0][j+1] = matrix[0][j] - '0';
        for (int i = 1; i < m; ++i)
            for (int j = 0; j < n; ++j)
                heights[i][j+1] = matrix[i][j] - '0' ? heights[i-1][j+1] + 1 : 0;

        int max_area = 0;
        vector<int> S;
        for (int i = 0; i < m; ++i) {
            S.clear(); S.push_back(0);
            for (int j = 1; j < n + 2; ++j) {
                while (heights[i][j] < heights[i][S.back()]) {
                    int k = S.back();
                    S.pop_back();
                    max_area = max(max_area, heights[i][k] * (j - S.back() - 1));
                }
                S.push_back(j);
            }
        }
        return max_area;
    }
};
