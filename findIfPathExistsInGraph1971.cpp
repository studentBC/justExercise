class Solution {
public:
   int find(vector<int> &ds, int i) 
   { 
       return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]); 
   }
bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    
    vector<int> ds(n, -1);
    
    for (auto &e : edges) {
        
        int p1 = find(ds, e[0]);
        int p2 = find(ds, e[1]);
        
        if (p1 != p2)
            ds[p2] = p1;
    }
    return find(ds, start) == find(ds, end);
}
};

//my slow solution
class Solution {
public:
    vector<bool>visited;
    void go (int start, int end, vector<unordered_set<int>>& graph, bool& ans) {
        if (ans) return;
        if (start == end) {
            ans = true; return;
        }
        visited[start] = true;
        for (int i : graph[start]) {
            if (!visited[i]) go (i, end, graph, ans);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<unordered_set<int>>graph(n);
        visited = vector<bool>(n, false);
        bool ans = false;
        for (auto& it: edges) {
            graph[it[0]].insert(it[1]);
            graph[it[1]].insert(it[0]);
        }
        go (start, end, graph, ans);
        return ans;
    }
};

