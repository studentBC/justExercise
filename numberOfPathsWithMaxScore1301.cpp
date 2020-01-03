class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int number[board.size()+1][board[0].size()+1];
        int path[board.size()+1][board[0].size()+1];
        int direct[] = {0,1,1,0};
        int x, y, val; 
        memset(number, 0, sizeof(number));
        memset(path, 0, sizeof(path));
        path[0][0] = 1;
        board.back().back() = board[0][0] = '0';
        for (int i = 1; i <= board.size(); i++) { 
            for (int j = 1; j <= board[0].size(); j++) {
                if (board[i-1][j-1] == 'X') continue;
                for (int k = 0; k < 3; k++) {
                    x = i-direct[k]; y = j-direct[k+1];
                    if (path[x][y]) {
                        val = number[x][y]+(board[i-1][j-1]-'0');
                        if (number[i][j] == val) {
                            path[i][j]+=path[x][y];
                            path[i][j]%=1000000007;
                            number[i][j] = val;
                        } else if (number[i][j] < val) {
                            path[i][j]=path[x][y];
                            path[i][j]%=1000000007;
                            number[i][j] = val;
                        }
                    }
                }
            }
        }
        return {number[board.size()][board[0].size()], path[board.size()][board[0].size()]};
    }
};
//the fatest solution
class Solution {
public:
    int x[3] = {1,0,1};
    int y[3] = {0,1,1};
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int n = b.size();        
        vector<vector<int>> sum(n+1, vector<int>(n+1,0)), paths(n+1, vector<int>(n+1,0));
        paths[0][0] = 1;
        b[0][0] = b[n-1][n-1]='0';
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(b[i-1][j-1]=='X')
                    continue;
                for(int k=0;k<3;k++)
                {
                    int pr = i-x[k];
                    int pc = j-y[k];                    
                    if(paths[pr][pc])
                    {
                        int val = b[i-1][j-1]-'0' + sum[pr][pc];
                        if(sum[i][j]<=val)
                        {
                            if(sum[i][j]==val)
                            {
                                paths[i][j] = (paths[i][j]+paths[pr][pc])%1000000007;
                            }
                            else
                                paths[i][j] = paths[pr][pc];
                            
                            sum[i][j] = val;
                        }
                    }
                }
//                cout<<"{"<<sum[i][j]<<","<<paths[i][j]<<"}";
            }            
            cout<<endl;
        }
        return {sum[n][n],paths[n][n]};
    }
};
