class Solution {
public:
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        } else if (board[click[0]][click[1]] == 'E') {
            queue<pair<int,int>>pos;
            vector<pair<int,int>>tmp;
            vector<vector<bool>>visited(board.size(), vector<bool>(board[0].size(), false));
            int step[5] = {0,1,0,-1,0};
            int slope[5] = {1,1,-1,-1,1};
            pos.push(make_pair(click[0], click[1]));
            int x, y, i, j, count, temp;
            while (!pos.empty()) {
                x = pos.front().first;
                y = pos.front().second;
                //cout << x <<" , " << y << endl;
                pos.pop();
                if (!visited[x][y]) {
                    temp = count = 0;
                    for (int a = 0; a < 4; a++) {
                        i = x+step[a];
                        j = y+step[a+1];
                        if (i > -1 && i < board.size() && j > -1 && j < board[0].size()) {
                            if (board[i][j] == 'M') {
                                count++;
                            } else if (board[i][j] == 'E') {
                                temp++;
                                tmp.emplace_back(make_pair(i,j));
                            }
                        }
                    }
                    for (int a = 0; a < 4; a++) {
                        i = x+slope[a];
                        j = y+slope[a+1];
                        if (i > -1 && i < board.size() && j > -1 && j < board[0].size()) {
                            if (board[i][j] == 'M') {
                                count++;
                            } else if (board[i][j] == 'E') {
                                temp++;
                                tmp.emplace_back(make_pair(i,j));
                            }
                        }
                    }
                    if (!count) {
                        board[x][y] = 'B';
                        for (int a = 0; a < temp; a++) pos.push(tmp[a]);
                    } else {
                        board[x][y] = count+'0';
                    }
                    visited[x][y] = true;
                    //cout <<"mark "<< x <<" , " << y << endl;
                    tmp.clear();
                }
            }
        }
        return board;
    }
};
//the fatest solution
class Solution {
    
public:
   Solution() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
   }
    
    bool valid(const vector<vector<char>>& board, int x, int y){
        return ( x>=0 && x<board.size() && y>=0 && y<board[0].size() );
    }
    
    void updateBoard(vector<vector<char>>& board, int row, int col) {
        if(!valid(board, row, col)) return;
        
        if(board[row][col] == 'E') {
            int val = 0;
            if(valid(board, row-1, col-1) && board[row-1][col-1] == 'M') val++;
            if(valid(board, row-1, col)   && board[row-1][col] == 'M') val++;
            if(valid(board, row-1, col+1) && board[row-1][col+1] == 'M') val++;
            if(valid(board, row, col+1)   && board[row][col+1] == 'M') val++;
            if(valid(board, row+1, col+1) && board[row+1][col+1] == 'M') val++;
            if(valid(board, row+1, col)   && board[row+1][col] == 'M') val++;
            if(valid(board, row+1, col-1) && board[row+1][col-1] == 'M') val++;
            if(valid(board, row, col-1)   && board[row][col-1] == 'M') val++;
            
            if(val) {
                board[row][col] = '0'+val;
            } else {
                board[row][col] = 'B';
                updateBoard(board, row-1,col-1);
                updateBoard(board, row-1,col);
                updateBoard(board, row-1,col+1);
                updateBoard(board, row,col+1);
                updateBoard(board, row+1,col+1);
                updateBoard(board, row+1,col);
                updateBoard(board, row+1,col-1);
                updateBoard(board, row,col-1);
            }
        } else if (board[row][col] == 'M') {
            board[row][col] = 'X';
        } 
        
        return;
        
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {                                                   
        updateBoard(board, click[0], click[1]);
        return board;
    }
};
