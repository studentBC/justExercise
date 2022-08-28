class Solution {
public:
    int row, col, len;
    bool valid(int x, int y) {
        return x > -1 && x < row && y > -1 && y < col;
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
       row = board.size(); col = board[0].size(); len = word.size();
        //check row
        int step[5] = {-1, 0, 1, 0, -1};
        int x, y, index;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0] || board[i][j] == ' ') {
                    for (int a = 0; a < 4; a++) {
                        if (!valid(i-step[a], j-step[a+1]) || board[i-step[a]][j-step[a+1]]=='#') {
                            x = i;
                            y = j;
                            index = 0;
                            while (index < len && valid(x, y)) {
                                if (board[x][y] == '#' || (board[x][y]!=' ' && board[x][y]!=word[index])) break;
                                index++;
                                x+=step[a];
                                y+=step[a+1];
                            }
                            if (index == len && (!valid(x, y) || board[x][y] == '#')) return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
