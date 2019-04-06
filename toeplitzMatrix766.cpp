class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int i = 0,j = 0, prev, last;
        bool same;
        for (j = 0; j < matrix[0].size(); j++) {
            i = 0;
            last = j;
            prev = matrix[i][j];
            //cout << prev <<" , ";
            while (i+1 < matrix.size() && j+1 < matrix[0].size()) {
                i++;j++;
                if (prev != matrix[i][j]) {
                    return false;
                }
            }
            j = last;
        }
        for (i = 1; i < matrix.size(); i++) {
            j = 0;
            last = i;
            prev = matrix[i][j];
            while (i+1 < matrix.size() && j+1 < matrix[0].size()) {
                i++;j++;
                if (prev != matrix[i][j]) {
                    return false;
                }
            }
            i = last;
        }
        return true;
    }
};
//the fatest method
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        //int size = matrix.size() + matrix[0].size() -1;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = m-1; i >= 0; --i)
        {
            int x =0, y =i;
            while (x < n && y < m)
                if (matrix[y++][x++] != matrix[i][0])
                    return false;
        }
        for(int j = 1; j < n; ++j)
        {
            int x =j, y =0;
            while (x < n && y < m)
                if (matrix[y++][x++] != matrix[0][j])
                    return false;
        }
        
        return true;
    }
};
