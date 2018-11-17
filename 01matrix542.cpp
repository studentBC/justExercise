class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int maxdist = m+n;
        int dr[]= {0, 0 , 1, -1};
        int dc[]= {1, -1, 0, 0};
        queue<pair<int,int>>q;
        //vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(),maxdist));
        
        
        for(int i = 0; i< m; i++){
            for(int j= 0; j<n; j++){
               if(matrix[i][j]==0)
                    q.push({i,j});
                else
                    matrix[i][j]= maxdist;
            }
        }
        
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            //traverse the neighbors
            for(int i = 0; i<4; i++){
                int nextr = curr.first + dr[i];
                int nextc = curr.second + dc[i];
                
                if(nextr>=0 && nextr<m && nextc>=0 && nextc<n && matrix[curr.first][curr.second]+1< matrix[nextr][nextc]){
                    q.push({nextr, nextc});
                    matrix[nextr][nextc] = matrix[curr.first][curr.second]+1;
                    }
                
            }
            
        }
        
        return matrix;
    }
};
//my method
 class Solution {
 public:
     vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
         vector<vector<int>>ans(matrix);
         pair<int,int>coordinate;
         vector<pair<int,int>>target;
         int distance , min = INT_MAX;
         for (int i = 0; i < matrix.size(); i++) {
             for (int j = 0; j < matrix[i].size(); j++) {
                 if (matrix[i][j] == 0) {
                     coordinate.first = i;
                     coordinate.second = j;
                     target.push_back(coordinate);
                 }
             }
         }
         //find 0 to 1 distance
         for (int i = 0; i < matrix.size(); i++) {
             for (int j = 0; j < matrix[i].size(); j++) {
                 if (matrix[i][j] == 1) {
                     min = INT_MAX;
                     for (int k = 0; k < target.size(); k++) {
                         distance = abs(target[k].first - i) + abs(target[k].second - j);
                         if (min > distance) min = distance;
                     }
                     ans[i][j] = min;
                 }
             }
         }
         return ans;
     }
 };
