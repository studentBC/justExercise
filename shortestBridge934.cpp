class Solution {
public:
    void go (int i , int j, vector<vector<int>>& A, vector<pair<int,int>>&temp) {
        if ( i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] != 1) return;
        temp.push_back(pair<int,int>(i,j));
        A[i][j]=2;
        go (i,j+1,A,temp);
        go (i+1,j,A,temp);
        go (i,j-1,A,temp);
        go (i-1,j,A,temp);
    }
    int shortestBridge(vector<vector<int>>& A) {
        vector<pair<int,int>>temp;
        vector<vector<pair<int,int>>>points;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                if (A[i][j] == 1) {
                    temp.clear();
                    go (i,j,A,temp);
                    points.push_back(temp);
                }
            }
        }
        //cout << "there are " << points.size() << " island" << endl;
        int distance, min = INT_MAX;
        for (int i = 0; i < points[0].size(); i++) {
            for (int j = 0; j < points[1].size(); j++) {
                distance = abs(points[0][i].first-points[1][j].first) + abs(points[0][i].second-points[1][j].second)-1;
                if (min > distance) {
                    min = distance;
                    if (min == 1) return 1;
                }
            }
        }
        return min;
    }
};
//the fatest method
class Solution {
public:
    void DFS(vector <vector <int>>& A, queue <int>& to_expand, int x, int y)
    {
        A[x][y] = 2;
        to_expand.push(x * N + y);
        for(int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i], next_y = y + dy[i];
            if(0 <= next_x && next_x < N && 0 <= next_y && next_y < N && A[next_x][next_y] == 1)
                DFS(A, to_expand, next_x, next_y);
        }
        return;
    }
    int shortestBridge(vector<vector<int>>& A) 
    {
        N = A.size();
        queue <int> to_expand;
        for(int x = 0; x < N && to_expand.empty(); x++)
            for(int y = 0; y < N && to_expand.empty(); y++)
                if(A[x][y] == 1)
                    DFS(A, to_expand, x, y);
        int distance = 0;
        while(to_expand.size() > 0)
        {
            int num = to_expand.size();
            for(int i = 0; i < num; i++)
            {
                int position = to_expand.front();
                to_expand.pop();
                int x = position / N, y = position % N;
                for(int j = 0; j < 4; j++)
                {
                    int next_x = x + dx[j], next_y = y + dy[j];
                    if(0 <= next_x && next_x < N && 0 <= next_y && next_y < N)
                    {
                        if(A[next_x][next_y] == 1)
                            return distance;
                        if(A[next_x][next_y] == 0)
                        {
                            A[next_x][next_y] = 2;
                            to_expand.push(next_x * N + next_y);
                        }
                    }
                }
            }
            distance++;
        }
        return 0;
    }
private:
    int N, dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
};
