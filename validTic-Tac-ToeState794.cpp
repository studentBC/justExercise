class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cross = 0 , circle = 0, count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') {
                    cross++;
                } else if (board[i][j] == 'O') {
                    circle++;
                }
            }
        }
        int diff = abs(cross-circle);
        int xline = 0, cline = 0;
        if (diff > 1) {
            return false;
        } else if (diff == 1) {
            if (cross < circle) return false;
        }
        if (cross > 2 && circle > 2) {
            //check row
            char prev;
            for (int i = 0; i < 3; i++) {
                prev = board[i][0];
                count = 1;
                for (int j = 1; j < 3; j++) {
                    if (board[i][j] == prev) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == 3) {
                    if (prev == 'X') xline++;
                    else if (prev == 'O') cline++;
                }
            }
            //check vertical
            for (int i = 0; i < 3; i++) {
                prev = board[0][i];
                count = 1;
                for (int j = 1; j < 3; j++) {
                    if (board[j][i] == prev) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == 3) {
                    if (prev == 'X') xline++;
                    else if (prev == 'O') cline++;
                }
            }
            //check diag
            if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                if (board[0][0] == 'X') {
                    xline++;
                } else if (board[0][0] == 'O') {
                    cline++;
                }
            }
            if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                if (board[0][2] == 'X') {
                    xline++;
                } else if (board[0][2] == 'O') {
                    cline++;
                }
            }
            if (xline && cline) return false;
        }
        //cout << cline <<" , " << xline << endl;
        //cout << circle <<" , " << cross << endl;
        if (xline) {
            //cout << "here" << endl;
            if (circle >= cross) return false;
        } else if (cline) {
            if (cross > circle) return false;
        }
        return true;
    }
};
//the fatest solution
class Solution {
public:
    pair<int, int> check(const vector<string>& b) {
        int x = 0, y = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (b[i][j] == 'X')
                    x++;
                else if (b[i][j] == 'O')
                    y++;
            }
        
        return make_pair(x, y);
    }
    
    int winner(const vector<string>& b) {
        int win = 0;
        for (int i = 0; i < 3; i++) {
            if (b[i][0] != ' ' && b[i][0] == b[i][1] && b[i][1] == b[i][2])
                win |= (b[i][0] == 'X') ? 1 : 2;
            if (b[1][i] != ' ' && b[0][i] == b[1][i] && b[1][i] == b[2][i])
                win |= (b[1][i] == 'X') ? 1 : 2;
        }
        
        if (b[0][0] != ' ' && b[0][0] == b[1][1] && b[1][1] == b[2][2])
            win |= (b[0][0] == 'X') ? 1 : 2;
        
        if (b[0][2] != ' ' && b[0][2] == b[1][1] && b[1][1] == b[2][0])
            win |= (b[0][2] == 'X') ? 1 : 2;
        
        return win;
    }
    
    bool validTicTacToe(vector<string>& board) {
        int win = winner(board);
        auto p(check(board));
        
        if (win == 0)
            return p.first == p.second || p.first == p.second + 1;
        else if (win == 1)
            return p.first == p.second + 1;
        else if (win == 2)
            return p.first == p.second;
        
        return false;
    }
};
