class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>>ans = M;
        int direct[5] = {0,1,0,-1,0};
        int diag[5] = {-1, -1, 1 ,1 ,-1};
        int x, y, total; long gray;
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[0].size(); j++) {
                gray = 0;total = 1;
                gray+=M[i][j];
                for (int a = 0; a < 4; a++) {
                    x = i + direct[a];
                    y = j + direct[a+1];
                    if (x > -1 && x < M.size() && y > -1 && y < M[0].size()) {
                        total++;
                        gray+=M[x][y];
                    }
                    x = i + diag[a];
                    y = j + diag[a+1];
                    if (x > -1 && x < M.size() && y > -1 && y < M[0].size()) {
                        total++;
                        gray+=M[x][y];
                    }
                }
                ans[i][j] = gray/total;
            }
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        const size_t h = M.size();
        if(h==0){
            return vector<vector<int>>();
        }
        const size_t w = M[0].size();
        if(w==0){
            return vector<vector<int>>();
        }
        vector<vector<int>> r(h, vector<int>(w));
        
        for(int i=0;i<h;++i){
            for(int j=0;j<w;++j){
                int s = M[i][j];
                int q = 1;
                if(i-1>=0 && j-1>=0){s+=M[i-1][j-1];++q;}
                if(i-1>=0)          {s+=M[i-1][j];  ++q;}
                if(i-1>=0 && j+1<w) {s+=M[i-1][j+1];++q;}
                if(j-1>=0)          {s+=M[i][j-1];  ++q;}
                if(j+1<w)           {s+=M[i][j+1];  ++q;}
                if(i+1<h  && j-1>=0){s+=M[i+1][j-1];++q;}
                if(i+1<h)           {s+=M[i+1][j];  ++q;}
                if(i+1<h  && j+1<w) {s+=M[i+1][j+1];++q;}
                r[i][j] = s/q;                
            }
        }
        return r;
    }
};
