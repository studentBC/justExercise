class Solution {
public:
    void go (int i, vector<vector<int>>& graph, vector<int>& timevisit, vector<int>& low, vector<int>& parent, vector<bool>& visited, vector<vector<int>>& ans) {
        static int time = 0;
        visited[i] = true;
        low[i] = timevisit[i] = ++time;
        for (int j: graph[i]) {
            if (!visited[j]) {
                parent[j] = i;
                go (j, graph, timevisit, low, parent, visited, ans);
                low[i] = min (low[i], low[j]);
                if (low[j] > timevisit[i]) ans.push_back({i,j});
            } else if (j != parent[i]) {
                low[i] = min (low[i], timevisit[j]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>graph(n, vector<int>());
        for (int i = 0; i < connections.size(); i++) {
            graph[connections[i][0]].emplace_back(connections[i][1]);
            graph[connections[i][1]].emplace_back(connections[i][0]);
        }
        vector<bool>visited(n, false);
        vector<int>low (n), timevisit(n), parent(n);
        vector<vector<int>>ans;
        int lowest;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                go (i,graph,timevisit,low,parent,visited,ans);
            }
        }
        return ans;
    }
};
//the fatest solution 608 msd
const int MAXN=100010;
const int MAXM=100010;

class Solution {
    //树的数组形式储存
    int Head[MAXN], Next[MAXM*2], To[MAXM*2]; 
    int n,tot;
    
    //dfn 储存每个定点的唯一编号
    //low 储存当前定点能到达的最小编号
    int dfn[MAXN],low[MAXN];
    
    int numIndex,numCutedge; //答案
    struct Edge{
        int u,v;
    }cutedge[MAXM];

    void Tarjan(int u,int pre = -1) {
        if(dfn[u] != -1) return;
        dfn[u] = low[u] = ++numIndex;//分配唯一编号
        
        for (int i = Head[u]; i != -1; i = Next[i]) {
            int v=To[i];
            if(v == pre)continue;
            Tarjan(v, u);
            
            low[u] = min(low[u], low[v]);//如有有更小编号，更新
            if (low[v] > dfn[u]) {
                cutedge[numCutedge++] = {u, v}; //找到一个答案
            } 
        }
    }
    
    void solve(){
        memset(dfn,-1,sizeof(dfn));
        memset(low,-1,sizeof(low));
        numCutedge = 0;
        numIndex = 0;
        Tarjan(0); //由于是连通图，随便找个定点开始搜就行了
    }
    void Outit(vector<vector<int>>& ans){
        for (int i = 0; i < numCutedge; i++){
            ans.push_back({cutedge[i].u,cutedge[i].v});
        }
    }
    void add_eage(int x, int y){
        tot++;
        Next[tot] = Head[x];
        Head[x] = tot;
        To[tot] = y;
    }
    void ReadInfo(int n, vector<vector<int>>& conn){
        memset(Head, -1, sizeof(Head));
        tot = 0;
        this->n = n;
        for(auto&v: conn){
            int x = v[0];
            int y = v[1];
            add_eage(x,y); 
            add_eage(y,x);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        ReadInfo(n, conn);
        solve();
        
        vector<vector<int>> ans;
        Outit(ans);
        return ans;
    }
};
