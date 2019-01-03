class Solution {
public:
	void go (int i , int j , vector<vector<char>>& board) {
		if (i >= board.size() || j>=board[0].size() || j <0 || i < 0  || board[i][j] != 'X')return;
		if (board[i][j] == 'X') board[i][j] = 'O';
		go (i, j+1, board);
		go (i+1, j, board);
		go (i, j-1, board);
		go (i-1, j, board);
		return;
	}
    int countBattleships(vector<vector<char>>& board) {
		int count = 0;
 		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == 'X') {
					go (i,j,board);
					count++;
				}
			}
		}
		return count;
    }
};
//the fatest method
class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    auto A = [&](int i, int j) {
      if (i < 0 || j < 0 || i >= m || j >= n) return '.';
      return board[i][j];
    };

    int count = 0;
    for (int i=0; i<m; ++i) {
      for (int j=0; j<n; ++j) {
        // Count the heads of the ships.
        if (A(i, j) == 'X' && A(i, j-1) == '.' && A(i-1, j) == '.') ++count;
      }
    }

    return count;
  }
};
