class Solution {
public:
    void go ( queue<pair<int,int>>&next, queue<int>&count, int* max, vector<vector<int>>& matrix) {
        int i , j , c;
        while(!next.empty()) {
            c = count.front();
            i = next.front().first;
            j = next.front().second;
            //cout << " at ( " << i <<" , "<<j<<" ) : " << c << endl;
            if (c > *max)*max = c;
            //go up 
            if (i>0) {
                if (matrix[i-1][j] > matrix[i][j]) {
                    next.push(pair<int,int>(i-1 , j));
                    count.push(c+1);
                }
            }
            //go right
            if (j < (int)matrix[0].size()-1) {
                if (matrix[i][j+1] > matrix[i][j]) {
                    next.push(pair<int,int>(i, j+1));
                    count.push(c+1);
                }   
            }
            //go down
            if (i < (int)matrix.size()-1) {
                if (matrix[i+1][j] > matrix[i][j]) {
                    next.push(pair<int,int>(i+1 , j));
                    count.push(c+1);
                }   
            }
            //go left
            if (j > 0) {
                if (matrix[i][j-1] > matrix[i][j]) {
                    next.push(pair<int,int>(i , j-1));
                    count.push(c+1);
                }   
            }   
            next.pop();
            count.pop();
        }   
            return;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
		cout << matrix.size() << " , " << matrix[0].size() << endl;
        queue<pair<int,int>>next;
        queue<int>count;
        int* max = (int*)malloc(sizeof(int));
        *max = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                next.push(pair<int,int>(i,j));
                count.push(1);
                go (next, count, max, matrix);
            }
        }
        return *max;
    }

};
//fatest method
static int __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 0) return 0;
        int cols = matrix[0].size();
        vector<vector<int> > dist(rows, vector<int>(cols, -1));
        int ret = -1;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                ret = max(ret, dfs(matrix, dist, i, j));
            }
        }
        return ret;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int> >& dist, int i, int j) {
        if(dist[i][j] >= 0) {
            return dist[i][j];
        }
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int rows = matrix.size();
        int cols = matrix[0].size();
        int subpath = 0;
        for(int k = 0; k  < 4; k++) {
            int ni = dir[k][0] + i;
            int nj = dir[k][1] + j;
            if(ni < 0 || ni >= rows || nj < 0 || nj >= cols)
                continue;
            if(matrix[ni][nj] > matrix[i][j])
                subpath = max(subpath, dfs(matrix,dist,ni,nj));
        }
        dist[i][j] = 1 + subpath;
        return 1 + subpath;
    }
    
    

};
