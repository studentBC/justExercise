typedef pair<int, int> pii;
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> gp;
        for (auto& edge : edges) {
            gp[edge[0]].push_back({edge[1], edge[2]});
            gp[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push({0, n});
        dist[n] = 0;
        
		int u, v, w;
        while (!pq.empty()) {
            pii p = pq.top(); pq.pop();
            u = p.second;
            for (auto& to : gp[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        vector<int> dp(n + 1, -1);
        return dfs(gp, n, dp, dist);
    }
    
    int dfs(unordered_map<int, vector<pair<int, int>>>& gp, int s, vector<int>& dp, vector<int>& dist) {
        int mod = 1e9+7;
        if (s == 1) return 1;
        if (dp[s] != -1) return dp[s];
        int sum = 0, weight, val;
        for (auto& n : gp[s]) {
            weight = dist[s];
            val = dist[n.first];
            if (val > weight) {
                sum = (sum % mod + dfs(gp, n.first, dp, dist) % mod) % mod;
            }
        }
        return dp[s] = sum % mod;
    }
};
// 432 ms solution
typedef pair<int,int> pi;
const int N=1e5;
const int mod=1e9+7;
vector<pi> g[N];
int dp[N];
int dist[N];
void dijakastra(int n)
{
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    pq.push({0,n});
    dist[n]=0;
    
    while(pq.size()>0)
    {
        int val=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        
        for(pi p:g[node])
        {
            int child=p.first;
            int w=p.second;
            
            if(dist[child]>dist[node]+w)
            {
                dist[child]=dist[node]+w;
                pq.push({dist[child],child});
            }
        }
        
    }
}

int dfs(int node,int end)
{
    if(node==end)
        return 1;
    if(dp[node]!=-1)
        return dp[node];
    
    int ans=0;
    for(pi p:g[node])
    {
        int child=p.first;
        if(dist[child]<dist[node])
            ans=(ans%mod+dfs(child,end)%mod)%mod;
    }
    
    return dp[node]=ans%mod;
}
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
         
        for(int i=0;i<=n;i++)
        {
            dist[i]=INT_MAX;
            dp[i]=-1;
            g[i].clear();
        }
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        
        dijakastra(n);
        int ans=dfs(1,n);
        return ans;
        
    }
};
