/*
 * Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Example:

Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
 */
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        paper = new int* [n];
        for (int i = 0; i < n; i++) paper[i] = new int [n];
        len = n;
    }
    //p1 = 0, p2 = 1
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int count = 0;
        if (player == 1) {
            paper[row][col] = 1;
            for (int i = 0; i < len; i++) {
                if (paper[row][i] == 1) {
                    count++;
                } else {
                    count = 0;break;
                }
            }
            if (count == len) return 1;
            for (int i = 0; i < len; i++) {
                if (paper[i][col] == 1) {
                    count++;
                } else {
                    count = 0;break;
                }
            }
            if (count == len) return 1;
            //top right to down left
            int i = row, j = col;
            count = 1;
            while (i-1 > -1 && j+1 < len) {
                if (paper[i-1][j+1] == 1) count++;
                i--;j++;
            }
            i = row, j = col;
            while (i+1 < len && j-1 > -1) {
                if (paper[i+1][j-1] == 1) count++;
                i++;j--;
            }
            if (count == len) return 1;
            count = 1;
            //top left to down right
            i = row, j = col;
            while (i-1 > -1 && j-1 > -1) {
                if (paper[i-1][j-1] == 1) count++;
                i--;j--;
            }
            i = row, j = col;
            while (i+1 < len && j+1 < len) {
                if (paper[i+1][j+1] == 1) count++;
                i++;j++;
            }
            if (count == len) return 1;
            return 0;
        } else {
            paper[row][col] = 2;
            for (int i = 0; i < len; i++) {
                if (paper[row][i] == 2) {
                    count++;
                } else {
                    count = 0;break;
                }
            }
            if (count == len) return 2;
            for (int i = 0; i < len; i++) {
                if (paper[i][col] == 2) {
                    count++;
                } else {
                    count = 0;break;
                }
            }
            if (count == len) return 2;
            //top right to down left
            count = 1;
            int i = row, j = col;
            while (i-1 > -1 && j+1 < len) {
                if (paper[i-1][j+1] == 2) count++;
                i--;j++;
            }
            i = row, j = col;
            while (i+1 < len && j-1 > -1) {
                if (paper[i+1][j-1] == 2) count++;
                i++;j--;
            }
            if (count == len) return 2;
            count = 1;
            //top left to down right
            i = row, j = col;
            while (i-1 > -1 && j-1 > -1) {
                if (paper[i-1][j-1] == 2) count++;
                i--;j--;
            }
            i = row, j = col;
            while (i+1 < len && j+1 < len) {
                if (paper[i+1][j+1] == 2) count++;
                i++;j++;
            }
            if (count == len) return 2;
            return 0;
        }
        
    }
private:
    int ** paper;
    int len;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
//the fatest method
class TicTacToe {
private:
    int size;
    vector<int>rowV;
    vector<int>colV;
    vector<int>diagV;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size = n;
        rowV = vector<int> (n, 0);
        colV = vector<int> (n, 0);
        diagV = vector<int> (2, 0);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int val = player == 1 ? 1 : -1;
        if (((rowV[row] += val) == size * val)
            || ((colV[col] += val) == size * val)
            || (row == col && (diagV[0] += val) == size * val)
            || (row == size - 1 - col && (diagV[1] += val) == size * val)
           )
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
