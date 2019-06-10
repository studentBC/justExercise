class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        set<int>a,b;
        std::set<int>::iterator ita, itb;
        unordered_set<int>beenTo;
        vector<int>candidate;
        int start = 1;
        while (beenTo.size() != N) {
            if (candidate.size() > 0) {
                while (!candidate.empty() && beenTo.find(candidate.back())!=beenTo.end()) {
                    candidate.pop_back();
                }
                if (!candidate.empty()) {
                    start = candidate.back();
                } else {
                    for (int i = 1; i <= N; i++) {
                        if (beenTo.find(i) == beenTo.end()) {
                            start = i;
                            break;
                        }
                    }
                }   

            } else {
                for (int i = 1; i <= N; i++) {
                    if (beenTo.find(i) == beenTo.end()) {
                        start = i;
                        break;
                    }
                }
            }
            beenTo.insert(start);
            ita = a.find(start); itb = b.find(start);
            //cout <<"start from " << start << endl;
            if (ita == a.end() && itb == b.end()) {
                a.insert(start);
                for (int j = 0; j < dislikes.size(); j++) {
                    if (dislikes[j][0] == start) {
                        if (a.find(dislikes[j][1])!=a.end()) return false;
                        b.insert(dislikes[j][1]);
                        candidate.emplace_back(dislikes[j][1]);
                    } else if (dislikes[j][1] == start) {
                        if (a.find(dislikes[j][0])!=a.end()) return false;
                        b.insert(dislikes[j][0]);
                        candidate.emplace_back(dislikes[j][0]);
                    }
                }   
            } else if (ita != a.end()) {
                for (int j = 0; j < dislikes.size(); j++) {
                    if (dislikes[j][0] == start) {
                        if (a.find(dislikes[j][1])!=a.end()) return false;
                        b.insert(dislikes[j][1]);
                        candidate.emplace_back(dislikes[j][1]);
                    } else if (dislikes[j][1] == start) {
                        if (a.find(dislikes[j][0])!=a.end()) return false;
                        b.insert(dislikes[j][0]);
                        candidate.emplace_back(dislikes[j][0]);
                    }  
                }  
            } else if (itb != b.end()) {
                for (int j = 0; j < dislikes.size(); j++) {
                    if (dislikes[j][0] == start) {
                        if (b.find(dislikes[j][1])!=b.end()) return false;
                        a.insert(dislikes[j][1]);
                        candidate.emplace_back(dislikes[j][1]);
                    } else if (dislikes[j][1] == start) {
                        if (b.find(dislikes[j][0])!=b.end()) return false;
                        a.insert(dislikes[j][0]);
                        candidate.emplace_back(dislikes[j][0]);
                    }  
                }  
            }
            /*
            cout << "-----------------------" << endl <<"a: ";
            for (int n:a) cout << n <<" , ";
            cout << endl <<"b: ";
            for (int n:b) cout << n <<" , ";
            cout << endl << "--------------------" << endl;*/
        }  
        return true;
    }
};
//the fatest method
class Solution {
public:
    vector <int> v[2005];
    int visited[2005];
    void initialize()
    {
        for(int i=0;i<2005;i++)
            visited[i]=0;
    }
    
    bool dfs(int u,int p)
    {
        visited[u]=p;
        bool q=true;
        for(int i=0;i<v[u].size();i++)
        {
            if(p==1 && visited[v[u][i]]==1)
                return false;
            else if(p==2 && visited[v[u][i]]==2)
                return false;
            else if(p==1 && visited[v[u][i]]==0)
                q = dfs(v[u][i],2);
            else if(p==2 && visited[v[u][i]]==0)
                q = dfs(v[u][i],1);
            
            if(q==false)
                return false;
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dis) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int m = dis.size();
        bool p=true,q;
        if(N==1)
            return true;
        initialize();
        for(int i=0;i<m;i++)
        {
            v[dis[i][0]].push_back(dis[i][1]);
            v[dis[i][1]].push_back(dis[i][0]);
        }
        for(int i=1;i<=N;i++)
        {
            if(visited[i]==0)
            {
                q = dfs(i,1);
                p=p&q;
            }
        }
        return p;
    }
};
