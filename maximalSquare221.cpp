class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
 		vector<vector<int>>dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
		int length = 0;
		for (int i = 0; i <= matrix.size(); i++) {
			for (int j = 0; j <= matrix[0].size(); j++) {
				if (!i || !j || matrix[i-1][j-1] == '0') {
					dp[i][j] = 0;
				} else {
					dp[i][j] = min (dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
				}
				length = max (length, dp[i][j]);
			}
		}
		return length*length;
    }
};
//the fatest solution
int _ = []() { ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); return 0; }();

class Solution {
public:
//     int maxSquare(const vector<vector<char>>& matrix, vector<vector<int>>& max_squares, int i, int j) {
//         if(i >= matrix.size() or 
//            j >= matrix[i].size() or
//            matrix[i][j] != '1') return 0;
        
//         if(max_squares[i][j] != -1) return max_squares[i][j];
//         max_squares[i][j] = std::min({maxSquare(matrix, max_squares, i + 1, j),
//                                       maxSquare(matrix, max_squares, i, j + 1),
//                                       maxSquare(matrix, max_squares, i + 1, j + 1)}) + 1;
//         return max_squares[i][j];
//     }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        int max_square = 0;
        vector<vector<int>> max_squares(matrix.size(), vector<int>(matrix[0].size()));

        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(i == 0 or j == 0) 
                    max_squares[i][j] = matrix[i][j] == '1' ? 1 : 0;
                else if(matrix[i][j] == '1')
                    max_squares[i][j] = std::min({max_squares[i - 1][j],
                                                  max_squares[i][j - 1],
                                                  max_squares[i - 1][j - 1]}) + 1;
                max_square = std::max(max_square, max_squares[i][j]);
            }
        }
        
        return max_square * max_square;
    }
};
