class Solution {
public:
    vector<string>ans;
    unordered_map<string, vector<pair<string, int>> >graph;
    vector<bool>used;
    void go (string start, int count, vector<string>& route) {
        if (ans.size() > 0) return;
        if (count == 0) {
            if (ans.size() < route.size()) {
                ans = route;
                return;
            }
            for (int i = 0; i < route.size(); i++) {
                if (ans[i] > route[i]) {
                    ans = route;
                    return;
                } else if (ans[i] < route[i]) return;
            }
            return;
        }
        for (auto& it: graph[start]) {
            if (!used[it.second]) {
                route.push_back(it.first);
                used[it.second] = true;
                go (it.first, count-1, route);
                used[it.second] = false;
                route.pop_back();
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i = 0; i < tickets.size(); i++) {
            graph[tickets[i][0]].push_back({tickets[i][1], i});
        }
        for (auto& it: graph) {
            sort(it.second.begin(), it.second.end());
        }
        used = vector<bool>(tickets.size(), false);
        vector<string>route;
        go ("JFK", tickets.size(), route);
        ans.insert(ans.begin(), "JFK");
        return ans;
    }
};
