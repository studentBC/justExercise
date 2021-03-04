class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>>ans(rowSum.size(), vector<int>(colSum.size(), 0));
        int rend = rowSum.size(), cend = colSum.size();
        for (int i = 0; i < rend; i++) {
            for (int j = 0; j < cend; j++) {
                if (rowSum[i] > colSum[j]) {
                    ans[i][j] = colSum[j];
                    colSum[j]-=ans[i][j];
                    rowSum[i]-=ans[i][j];
                } else {
                    ans[i][j] = rowSum[i];
                    colSum[j]-=ans[i][j];
                    rowSum[i]-=ans[i][j];
                }
            }
        }
        
        return ans;
    }
};
//the 36 ms solution
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>>m(rowSum.size(),vector<int>(colSum.size()));
        for(int x=0,y=0;x<rowSum.size()&&y<colSum.size();){
            m[x][y] = min(rowSum[x],colSum[y]);
            rowSum[x] -= m[x][y];
            colSum[y] -= m[x][y];
            x += rowSum[x]==0;
            y += colSum[y]==0;
        }
        return m;
    }
};
