class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() > 0 && board[0].size() == 0) return;
        vector<vector<int>> next (board.size(), vector<int>(board[0].size(),0));
        int live = 0;

            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    live = 0;
                    //check 8 direction
                    if (i > 0 && j > 0 && board[i-1][j-1] == 1) {
                        live++;
                    }
                    if (i > 0 && board[i-1][j] == 1) {
                        live++;
                    }
                    if (i > 0 && j+1 < board[0].size() && board[i-1][j+1] == 1) {
                        live++;
                    }
                    if (j > 0 && board[i][j-1] == 1) {
                        live++;
                    }
                    if (j+1 < board[0].size() && board[i][j+1] == 1) {
                        live++;
                    }
                    if (i+1 < board.size() && j > 0 && board[i+1][j-1] == 1) {
                        live++;
                    }
                    if (i+1 < board.size() && board[i+1][j] == 1) {
                        live++;
                    }
                    if (i+1 < board.size() && j+1 < board[0].size() && board[i+1][j+1] == 1) {
                        live++;
                    }
                    //determine next generation
                    if (board[i][j] == 1) {
                        if (live < 2 || live > 3) {
                            next[i][j] = 0;
                        } else {
                            next[i][j] = 1;
                        }
                    } else {
                        if (live == 3) {
                            next[i][j] = 1;
                        } else {
                            next[i][j] = 0;
                        }
                    }
                }
            }
            //cout <<"--------------------"<<endl;
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    //cout << next[i][j] << " , ";
                    board[i][j] = next[i][j];
                }
                //cout << endl;
            }

        return;
    }
};

