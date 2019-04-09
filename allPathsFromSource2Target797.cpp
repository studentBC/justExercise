class Solution {
public:
    void go (int start, vector<vector<int>>& graph, vector<int>&temp, vector<vector<int>>& ans) {
        if (start == graph.size()-1) {
            ans.push_back(temp);
        }
        for (int i = 0; i < graph[start].size(); i++) {
            temp.push_back(graph[start][i]);
            go (graph[start][i], graph, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>temp;
        temp.push_back(0);
        go (0,graph,temp,ans);
        return ans;
    }
};
