class Solution {
public:
    void go (int i, int j, vector<vector<int>>& A, bool& touch, int& size) {
        if (i >= A.size() || i < 0 || j >= A[0].size() || j < 0 || A[i][j] != 1 ) return;
        if (i == A.size()-1 || i == 0 || j == A[0].size()-1 || j == 0) {
            touch = true;
        }
        size++;
        A[i][j] = -2;
        go (i-1,j,A,touch,size);
        go (i,j+1,A,touch,size);
        go (i+1,j,A,touch,size);
        go (i,j-1,A,touch,size);
    }
    int numEnclaves(vector<vector<int>>& A) {
       bool touch;
       int size = 0, ans = 0;
       for (int i = 0; i < A.size(); i++) {
           for (int j = 0; j < A[i].size(); j++) {
               if (A[i][j] == 1) {
                    touch = false;
                    size = 0;
                    go (i,j,A,touch, size);
                    if (!touch) {
                        ans+=size;
                    } 
               }
           }
       }
       return ans;
    }
};
//the fatest method

class Solution {
public:
    void Mark(vector<vector<int>>& A, int r, int c)
    {
        if (r < 0 || r >= A.size() || c < 0 || c >= A[r].size())
            return;
        if (A[r][c] != 1)
            return;
        A[r][c] = 0;
        Mark(A, r - 1, c);
        Mark(A, r, c - 1);
        Mark(A, r + 1, c);
        Mark(A, r, c + 1);
    }
    int numEnclaves(vector<vector<int>>& A) {        
        for (int i = 0; i < A[0].size(); ++i)
        {
            Mark(A, 0, i);
            Mark(A, A.size() - 1, i);
        }
        for (int i = 0; i < A.size(); ++i)
        {
            Mark(A, i, 0);
            Mark(A, i, A[0].size() - 1);
        }
        int num = 0;
        for (auto && i : A)
            for (int j : i)
                num += j;
        return num;
    }
};
