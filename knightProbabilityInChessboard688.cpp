class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<pair<int,int>>direct = {{-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-1, -2}, {1, -2}, {-2, 1}, {-2, -1}};
        vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K+1, 0))); 
        queue<tuple<int,int,int>>pos;
        pos.push(make_tuple(r,c,0));
        dp[r][c][0] = 1;
        int x, y, time, xx, yy;
        for (int i = 1; i <= K; i++)  {
            queue<tuple<int,int,int>>temp;
            unordered_set<string>visited;
            while (!pos.empty()) {
                x = get<0>(pos.front());
                y = get<1>(pos.front());
                //cout << x <<" , " << y << endl;
                time = get<2>(pos.front());
                pos.pop(); 
                for (int j = 0; j < 8; j++) {
                    xx = x+direct[j].first; 
                    yy = y+direct[j].second;
                    string tmp = to_string(xx)+" , "+to_string(yy);
                    if (xx > -1 && xx < N && yy > -1 && yy < N) {
                        if (!visited.count(tmp)) {
                            temp.push(make_tuple(xx, yy, time+1));
                            visited.insert(tmp);
                        }
                        dp[xx][yy][time+1] += dp[x][y][time];
                    }   
                }
            }
            /*for (int k = 0; k < N; k++) {
                for (int j = 0; j < N; j++) {
                    cout << dp[k][j][i] << " , ";
                }   
                cout << endl;
            }
            cout <<"------------------------" << endl;*/
            pos = temp;
        }
        double sum = 0, total = pow (8,K);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //cout << dp[i][j][K] <<" , ";
                sum+=dp[i][j][K];
            }   
            //cout << endl;
        }

        return sum/total;
    }
};
//the fatest solution
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if (K == 0){ return 1; }
        vector<vector<double> > prevDp(N, vector<double>(N, 0));
        vector<vector<double> > currDp(N, vector<double>(N, 0));

        // init K == 1
        if (r-1>=0 && c-2>=0){prevDp[r-1][c-2] = 1/8.0;}
        if (r-2>=0 && c-1>=0){prevDp[r-2][c-1] = 1/8.0;}
        if (r-2>=0 && c+1<N){prevDp[r-2][c+1] = 1/8.0;}
        if (r-1>=0 && c+2<N){prevDp[r-1][c+2] = 1/8.0;}
        if (r+1<N && c-2>=0){prevDp[r+1][c-2] = 1/8.0;}
        if (r+2<N && c-1>=0){prevDp[r+2][c-1] = 1/8.0;}
        if (r+2<N && c+1<N){prevDp[r+2][c+1] = 1/8.0;}
        if (r+1<N && c+2<N){prevDp[r+1][c+2] = 1/8.0;}

        for (int step = 2; step <= K; step++){
            for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){
                    double sum = 0;
                    if (i-1>=0 && j-2>=0){sum += prevDp[i-1][j-2]/8.0;}
                    if (i-2>=0 && j-1>=0){sum += prevDp[i-2][j-1]/8.0 ;}
                    if (i-2>=0 && j+1<N){sum += prevDp[i-2][j+1]/8.0;}
                    if (i-1>=0 && j+2<N){sum += prevDp[i-1][j+2]/8.0;}
                    if (i+1<N && j-2>=0){sum += prevDp[i+1][j-2]/8.0;}
                    if (i+2<N && j-1>=0){sum += prevDp[i+2][j-1]/8.0;}
                    if (i+2<N && j+1<N){sum += prevDp[i+2][j+1]/8.0;}
                    if (i+1<N && j+2<N){sum += prevDp[i+1][j+2]/8.0;}
                    currDp[i][j] = sum;
                }
            }
            prevDp.swap(currDp);
        }

        // sum up total count on the board;
        double onBoard = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                onBoard += prevDp[i][j];
                //if (prevDp[i][j] > 0) cout << i << " " << j << endl;
            }
        }
        return onBoard;
    }
};

