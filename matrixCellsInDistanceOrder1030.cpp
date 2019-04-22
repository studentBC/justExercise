class Solution {
public:
    static bool compare (pair<int,int>a , pair<int,int>b) {
        return a.second < b.second;
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>>cordinate;
        vector<vector<int>>ans;
        vector<int>temp;
        vector<pair<int,int>>distance;
        int count = 0, dis;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                dis = abs(i-r0)+abs(j-c0);
                distance.emplace_back (pair<int,int>(count,dis));
                temp.clear();
                temp.emplace_back (i);
                temp.emplace_back (j);
                cordinate.emplace_back(temp);
                count++;
            }
        }
        //cout << count << "   " << cordinate.size() <<endl;
        sort(distance.begin(), distance.end(), compare);
        for (int i = 0; i < distance.size(); ++i) {
            ans.emplace_back (cordinate[distance[i].first]);
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    struct Node {
        int x,y,dist;
        bool operator<(const Node &X) const { 
            return dist > X.dist; 
        } 
    };
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ANS(R, vector<int>(C,INT_MAX));
        vector<vector<int>> ANS2;
        
        
        queue<Node> Q;
        Q.push({r0,c0,0});
        ANS[r0][c0] = 0;
        
        while(!Q.empty()) {
            Node F = Q.front();
            Q.pop();
            
            int x = F.x;
            int y = F.y;
            int dist = F.dist;
            ANS2.push_back({F.x,F.y});
            
            for(int i=0;i<4;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx>=0 && nx<R && ny>=0 && ny<C) {
                    if(ANS[nx][ny] > dist + 1) {
                        ANS[nx][ny] = dist + 1;
                        Q.push({nx,ny,dist+1});
                    }
                }
            }
            
        }
        
        return ANS2;
    }
};
