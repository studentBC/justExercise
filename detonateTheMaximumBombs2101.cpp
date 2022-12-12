class Solution {
public:
    int ans = 0, len;
    void go (int start, vector<vector<bool>>& graph, unordered_set<int>& visited) {
        vector<int>next;
        for (int i = 0; i < len; i++) {
            if (graph[start][i] && !visited.count(i)) {
                next.push_back(i);
                visited.insert(i);
            }
        }
        for (int i : next) go (i, graph, visited);
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        len = bombs.size();long long x, y, z;
        vector<vector<bool>>graph(len, vector<bool>(len, false));
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (i == j) {
                    graph[i][j] = true;
                } else {
                    x = bombs[i][0]-bombs[j][0];
                    y = bombs[i][1]-bombs[j][1];
                    z = bombs[i][2];
                    if (x*x+y*y <= z*z) graph[i][j] = true;
                }
            }
        }
        for (int i = 0; i < len; i++) {
            unordered_set<int>visited;
            go (i, graph, visited);
            ans = max(ans, (int)visited.size());
        }
        return ans;
    }
};
