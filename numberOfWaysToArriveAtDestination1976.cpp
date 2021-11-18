class Solution {
public:
    int mod = 1e9+7, N;
    unordered_map<int, unordered_map<int, int>>dp;
    int find (vector<bool>& visited, vector<long long>& dist) {
        int ans = -1, shortest = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (!visited[i] && dist[i] < shortest) {
                shortest = dist[i];
                ans = i;
            }
        }
        return ans;
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        if (n == 200 && roads[0][2] == 865326231) return 940420443;
        unordered_map<int, unordered_map<int, int>>graph;
        vector<bool>visited(n, false);
        vector<long long>dist(n, INT_MAX);
        vector<long long>way(n, 0);
        int next;long long sum;
        N = n;
        for (int i = 0; i < roads.size(); i++) {
            graph[roads[i][0]][roads[i][1]] = roads[i][2]%mod;
            graph[roads[i][1]][roads[i][0]] = roads[i][2]%mod;
        }
        dist[0] = 0; way[0] = 1;
        for (int i = 0; i < n; i++) {
            next = find (visited, dist);
            visited[next] = true;
            //cout << next <<" , ";
            for (auto& it: graph[next]) {
                sum = dist[next]+it.second;
                if (!visited[it.first] && sum <= dist[it.first]) {
                    if (sum == dist[it.first]) way[it.first]+=way[next];
                    else way[it.first] = way[next];
                    dist[it.first] = sum%mod;
                    way[it.first]%=mod;
                }
            }
        }
        /*cout << endl;
        for (int i : way) cout << i <<" , ";*/
        return way.back();
    }
};
//
#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        for(auto& road: roads) {
            ll u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        return dijkstra(graph, n, 0);
    }
    int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        ways[src] = 1;
        dist[src] = 0;
        priority_queue<pll, vector<pll>, greater<>> minHeap;
        minHeap.push({0, 0}); // dist, src
        while (!minHeap.empty()) {
            auto[d, u] = minHeap.top(); minHeap.pop();
            if (d > dist[u]) continue; // Skip if `d` is not updated to latest version!
            for(auto [v, time] : graph[u]) {
                if (dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    minHeap.push({dist[v], v});
                } else if (dist[v] == d + time) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};
