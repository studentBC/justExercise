class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int count , ans = 0;
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[i].size(); j++) {
                if (M[i][j]) {
                    count = 1;
                    for (int a = j-1; a > -1; a--) {
                        if (M[i][a]) count++;
                        else break;
                    }
                    for (int a = j+1; a < M[i].size(); a++) {
                        if (M[i][a]) count++;
                        else break;
                    }
                    ans = max (count, ans);
                    count = 1;
                    for (int a = i-1; a > -1; a--) {
                        if (M[a][j]) count++;
                        else break;
                    }
                    for (int a = i+1; a < M.size(); a++) {
                        if (M[a][j]) count++;
                        else break;
                    }
                    ans = max (count, ans);
                    count = 1;
                    for (int a = i-1, b = j-1; a > -1 && b > -1; a--, b--) {
                        if (M[a][b]) count++;
                        else break;
                    }
                    for (int a = i+1, b = j+1; a < M.size() && b < M[i].size(); a++,b++) {
                        if (M[a][b]) count++;
                        else break;
                    }
                    ans = max (count, ans);
                    count = 1;
                    for (int a = i-1, b = j+1; a > -1 && b < M[i].size(); a--, b++) {
                        if (M[a][b]) count++;
                        else break;
                    }
                    for (int a = i+1, b = j-1; a < M.size() && b > -1; a++,b--) {
                        if (M[a][b]) count++;
                        else break;
                    }
                    ans = max (count, ans);
                }
            }
        }
        return ans;
    }
};
//the 20 ms solution
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int rows = M.size(), cols = rows ? M[0].size() : 0;
        if(cols == 0)
            return 0;
        
        int res = 0, count = 0;
        for(int r=0; r < rows; r++) // horizontal
        {
            count = 0;
            for(int c=0;  c < cols; c++ )
            {
                count = M[r][c] ? count+1 : 0;
                res = max(res, count);
            }
        }
        
        for(int c=0; c < cols; c++ ) // vertical
        {
            count = 0;            
            for(int r=0; r < rows; r++)
            {
                count = M[r][c] ? count+1 : 0;
                res = max(res, count);
            }
        }
        
        // diagonal 
        for(int col = -rows+1; col < cols; col++ )
        {
            count = 0;
            int r = 0, c = col;
            if( col < 0)
            {
                c = 0;
                r = -col;
            }
            
            for(    ; r < rows && c < cols; r++, c++)
            {
                count = M[r][c] ? count+1 : 0;
                res = max(res, count);
            }                
        }
        
        // anti-diagonal 
        for(int col=0, limit = cols + rows - 1; col < limit; col++ )
        {
            count = 0;
            int r = 0, c = col;
            if( col >= cols )
            {
                c = cols-1;
                r = col - (cols-1);
            }
            
            for(    ; r < rows && c >= 0; r++, c--)
            {
                count = M[r][c] ? count+1 : 0;
                res = max(res, count);
            }
        }
        
        return res;
    }
};

