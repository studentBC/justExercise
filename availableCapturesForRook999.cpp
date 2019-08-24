class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int i, j, count = 0;
        for (int a = 0; a < board.size(); a++) {
            for (int b = 0; b < board[a].size(); b++) {
                if (board[a][b] == 'R') {
                    i = a; j = b;
                    while (i-1 > -1) {
                        i--;
                        if (board[i][j] == 'B') {
                            break;
                        } else if (board[i][j] == 'p') {
                            count++;
                            //cout <<"up "<<endl;
                            break;
                        }
                    }
                    i = a;
                    while (i+1 < board.size()) {
                        i++;
                        if (board[i][j] == 'B') {
                            break;
                        } else if (board[i][j] == 'p') {
                            cout <<"down "<<endl;
                            count++;break;
                        }
                    }
                    i = a;
                    while (j+1 < board[0].size()) {
                        j++;
                        if (board[i][j] == 'B') {
                            break;
                        } else if (board[i][j] == 'p') {
                            //cout <<"right "<<endl;
                            count++;break;
                        }
                    }
                    j = b;
                    while (j-1 > -1) {
                        j--;
                        if (board[i][j] == 'B') {
                            break;
                        } else if (board[i][j] == 'p') {
                            //cout <<"left "<<endl;
                            count++;break;
                        }
                    }
                    return count;
                }
            }
        }
        return 0;
    }
};
