class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        bool found = true, row;
        int vertical = 0, horizon = 0, c = 0;
        while (found) {
            found = false;
            vector<vector<bool>>mark(board.size(), vector<bool>(board[0].size(), false));
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    row = false;
                    if (board[i][j] > 0) {
                        //check up 
                        vertical = horizon = 1;
                        for (int k = i-1; k > -1; k--) {
                            if (board[k][j] == board[i][j]) vertical++;
                            else break;
                        }
                        for (int k = i+1; k < board.size(); k++) {
                            if (board[k][j] == board[i][j]) vertical++;
                            else break;
                        }
                        //check horizontal
                        for (int k = j+1; k < board[0].size(); k++) {
                            if (board[i][k] == board[i][j]) horizon++;
                            else break;
                        }
                        for (int k = j-1; k > -1; k--) {
                            if (board[i][k] == board[i][j]) horizon++;
                            else break;
                        }
                        if (vertical > 2) {
                            for (int k = i-1; k > -1; k--) {
                                if (board[k][j] == board[i][j]) mark[k][j] = true;
                                else break;
                            }
                            for (int k = i+1; k < board.size(); k++) {
                                if (board[k][j] == board[i][j]) mark[k][j] = true;
                                else break;
                            }
                            row = found = true;
                        }
                        if (horizon > 2) {
                            for (int k = j+1; k < board[0].size(); k++) {
                                if (board[i][k] == board[i][j]) mark[i][k] = true;
                                else break;
                            }
                            for (int k = j-1; k > -1; k--) {
                                if (board[i][k] == board[i][j]) mark[i][k] = true;
                                else break;
                            }
                            row = found = true;
                        }
                        if (row) {
                            //cout <<i<<" , "<< j << endl;
                            board[i][j] = -1;
                        }
                    }
                }
            }
            //fall candy
            if (found) {
                vector<vector<int>>temp(board.size(), vector<int>(board[0].size(), 0));
                for (int j = 0; j < board[0].size(); j++) {
                    c = board.size()-1;
                    for (int i = board.size()-1; i > -1; i--) {
                        if (board[i][j] > 0 && !mark[i][j]) {
                            temp[c][j] = board[i][j];
                            c--;
                        }
                    }
                }
                board = temp;
            }
        }
        return board;
    }
};
//the fatest solution

static int x = [](){cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); return 0;}();
class Solution {
    // the rule is different than marking island.  do not crash if the number of same-value connected nodes >= 3, rather the counts of horization and vertical are sepearted
    // crash if the number of same-value horization connected nodes >= 3, and crash if the number of same-value vertical connected nodes >= 3
    // therefore, scan from top to botom and only check the right neigbhours, then down neigbhours, seperately
    // when find the nodes to be crashed, mark it negivitve, note do not mark it to zero yet since further nodes may connect this node to form a size >= 3
    // After scanning the whole board, move down nodes > 0 (with write index) and fill the top spaces with 0s
    // repeat the above steps until nothing crashed after scanning the whole board (use a flag and set to true if anything to be crashed)
private:
    vector<pair<int, int>> island;
    int n;
    int m;

    // update the board and drop candies
    void DropBoard (vector<vector<int>>& board)
    {
        for (int j = 0; j < m; ++j)
        {
            int write_i = n - 1;
            for (int i = n - 1; i >= 0; --i)
            {
                // move nodes > 0 to the spaces to be crashed
                if (board[i][j] > 0)
                    board[write_i--][j] = board[i][j];
            }
            // fill 0s up to the valid data
            for (int i = write_i; i >= 0; --i)
                board[i][j] = 0;   
        }
    }
    
    // find and mark col or row for connected candies
    bool markLine (vector<vector<int>>& board, int i, int j, bool col)
    {
        // the node might be part of the crashing nodes and therefore has been marked negitive
        // but it still can be used to connect other nodes in this run to crash more candies, therefore take the orignal (abs) value
        int target = abs(board[i][j]);
        int count = 0;
        int di = col;
        int dj = !col;
        
        // scan to the board edge untill a different value shows up, then cannot connect anymore
        while(i < n && j < m)
        {
            if (abs(board[i][j]) != target)
                break;
            ++count;
            i += di;
            j += dj;
        }
        // report nothing to be crashed in this direction
        if (count < 3)
            return false;
        // otherwise mark the nodes to be crashed to be negtivie
        while(count--)
        {
            i -= di;
            j -= dj;
            board[i][j] = - abs(board[i][j]);
        }
        // report there are nodes to be crashed
        return true;
    }
    
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        if (board.empty())
            return board;
        n = board.size();
        m = board[0].size();
        bool crashed = true;
        // rechecking for crashing if there were candies just got crashed and changed the layout of the board
        while(crashed)
        {   
            crashed = false;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    // skip empty slots created by previous candy crashing and dropping
                    if (board[i][j] == 0)
                        continue;
                    // check row direction
                    crashed |= markLine(board, i, j, 0);
                    // check col direction
                    crashed |= markLine(board, i, j, 1);
                }
            }
            // update board: crash and drop candies
            DropBoard(board);
        }
        
        return board;
    }
};
