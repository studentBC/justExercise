class Solution {
public:
    bool check (int x, int y, vector<vector<int>>& grid) {
        vector<int>count(9,0);
        for (int i = x; i < x+3; i++) {
            for (int j = y; j < y+3; j++) {
                if (grid[i][j]-1 < 9 && grid[i][j] > 0) {
                    count[grid[i][j]-1]++;
                    if (count[grid[i][j]-1] > 1) return false;
                } else {
                    return false;
                }
            }  
        }

        //diagonal
        int i = x, j = y, sum = 0, match = 0;
        for (int a = 0; a < 3; a++) {
            sum+=grid[i][j];
            i++;j++;
        }
        j = y+2;i = x;
        for (int a = 0; a < 3; a++) {
            match+=grid[i][j]; 
            j--;i++;
        }
        if (sum!=match) return false;
        //every row
        match = 0;
        i = x; j = y;
        for (int a = 0; a < 3; a++) {
            match = 0;j = y;
            for (int b = 0; b < 3; b++) {
                match += grid[i][j];
                j++;
            }
            if (match!=sum) return false;
            i++;
        }
        //every col
        match = 0;
        i = x; j = y;
        for (int a = 0; a < 3; a++) {
            match = 0;i = x;
            for (int b = 0; b < 3; b++) {
                match += grid[i][j];
                i++;
            }
            if (match!=sum) return false;
            j++;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rowend = grid.size()-3 , colend = grid[0].size()-3, count = 0;
        for (int i = 0; i <= rowend; i++) {
            for (int j = 0; j <= colend; j++) {
                if (check(i,j,grid))++count;
            }
        }
        return count;
    }
};

