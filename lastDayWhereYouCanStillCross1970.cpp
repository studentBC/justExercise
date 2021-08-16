class Solution {
public:
    int row, col;
    void go (int i, int j, vector<vector<bool>>& graph, bool& pass) {
        if (pass || i < 0 || i >= row || j < 0 || j >= col || !graph[i][j]) return;
        if (i+1 == row) {
            pass = true; return;
        }
        //cout << i <<" , " << j << endl;
        graph[i][j] = false;
        go (i+1, j, graph, pass);
        go (i, j+1, graph, pass);
        go (i-1, j, graph, pass);
        go (i, j-1, graph, pass);
    }
    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {
        row = r; col = c;
        int len = cells.size(), left = 0, right = len-1, mid; bool pass;
        while (left <= right) {
            mid = (left+right)/2;
            vector<vector<bool>>graph(row, vector<bool>(col, true));
            for (int i = 0; i <= mid; i++) graph[cells[i][0]-1][cells[i][1]-1] = false;
            for (int j = 0; j < col; j++) {
                pass = false;
                go (0, j, graph, pass);
                if (pass)break;
            }
            if (pass) {
                left = mid+1;
            } else right = mid-1;
        }
        return left;
    }
};
