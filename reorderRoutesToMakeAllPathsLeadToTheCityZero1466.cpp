class Solution {
public:
    int go (vector<vector<int>>& graph, vector<bool>& visited, int start) {
        int change = 0;
        visited[start] = true;
        for (auto& n: graph[start]) {
            if (!visited[abs(n)]) {
                change+=go(graph, visited, abs(n)) + (n > 0);
            }
        }
        return change;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>graph(n);
        for (auto& c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(-c[0]);
        }
        vector<bool>visited(n, false);
        return go(graph,  visited, 0);
    }
};
