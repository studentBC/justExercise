/*concept: Start at any node A and traverse the tree to find the furthest node from it, let's call it B.
Having found the furthest node B, traverse the tree from B to find the furthest node from it, lets call it C.
The distance between B and C is the tree diameter.*/
class Solution {
public:
    void getfar (int start, vector<vector<int>>& graph, unordered_set<int>& visited, int distance, int& dis, int& far) {
        if (visited.find(start) != visited.end())  return;
        visited.insert(start);
        if (distance > dis) {
            far = start;
            dis = distance;
        }
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i][0] == start ) {
                getfar (graph[i][1], graph, visited, distance+1, dis, far);
            } else if (graph[i][1] == start ) {
                getfar (graph[i][0], graph, visited, distance+1, dis, far);
            }
        }
    }
    int treeDiameter(vector<vector<int>>& edges) {
        int big = 0, count = 0, dis, far;

        unordered_set<int>visited;
        dis = 0;
        getfar (0, edges, visited, 0, dis, far);
        dis = 0;
        visited.clear();
        getfar (far, edges, visited, 0, dis, far);
        return dis;
    }
};
//the fatest solution
vector<int> E[10005];

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int me = 0;
        int degree[10005] = {};
        bool ex[10005] = {};
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            me = max(me, max(a, b));
            E[a].push_back(b);
            E[b].push_back(a);
            degree[a]++; degree[b]++;
        }
        
        queue<int> q;
        for (int i = 0; i <= me; i++) {
            if (degree[i] < 2) {
                ex[i] = true; q.push(i);
            }
        }
        int step = -1;
        bool flag = false;
        while (!q.empty()) {
            int orig = q.size();
            for (int s = q.size(); s > 0; s--) {
                int r = q.front(); q.pop();
                for (int next : E[r]) {
                    if (--degree[next] < 2 && !ex[next]) {
                        q.push(next); ex[next] = true;
                    }
                }
            }
            int news = q.size();
            if (orig == 2 && news == 0) {
                flag = true;
            }
            step++;
        }
        
        for (int i = 0; i <= me; i++) E[i].clear();
        int ans = step*2;
        if (flag) ans++;
        return ans;
        
    }
};

