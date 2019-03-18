class Solution {
public:
    bool find (int target, vector<int>&path) {
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == target) return true;
        }
        return false;
    }
    void go (int i, int j, vector<int>&path, bool& duplicate, vector<vector<int>>& graph) {
        if (duplicate || graph[i].size() == 0) {
            if ( !path.empty() && graph[i].size() == 0 && path.back() == i) {
                //cout <<  "at " <<i <<" , " << j <<"  erase " << path.back() << endl;
                path.pop_back();
            }
            return;
        }
        //cout << graph[i][j] << " => ";
        if (!find(graph[i][j], path)) {
            path.push_back (graph[i][j]);
            for (int a = j; a < graph[i].size(); a++) {
                go ( graph[i][a], 0, path, duplicate, graph);
            }
            if (!path.empty()&& path.back() == i)path.pop_back();
        } else {
            duplicate = true;
            return;
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>path;
        bool duplicate;
        vector<int>ans;
        for (int i = 0; i < graph.size(); i++) {
            duplicate = false;
            path.clear();
            //path.push_back(i);
            go (i, 0, path, duplicate, graph);
            if (!duplicate) {
                ans.push_back(i);
            }
            //cout << endl;
        }
        return ans;
    }
};
//the fatest method
// topological sorting with dp
bool dfs(vector<vector<int>>& graph, vector<int> &dp, int src) {
   if(dp[src])
       return 1 == dp[src];

    dp[src] = -1; // by default mark it as "cannnot be topologically sorted"
    for(auto node : graph[src])
        if(false == dfs(graph, dp, node))
            return false;
    return dp[src] = 1; // next node with zero outdegree
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int total_nodes = graph.size();
    vector<int> result, dp(total_nodes, 0);
    for(int i = 0; i < total_nodes; i++)
        if(dfs(graph, dp, i))
            result.push_back(i);
    
    return result;
} 
