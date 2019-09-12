class Solution {
public:
    void go (string start, unordered_map<string, vector<string>>& graph, unordered_map<string, vector<bool>>& visited, vector<string>& ans, int count) {
        if (ans.size() == count) return;
        for (int j = 0; j < graph[start].size(); j++) {
            if (!visited[start][j]) {
                visited[start][j] = true;
                ans.emplace_back(graph[start][j]);
                go (graph[start][j], graph, visited, ans, count);
                 if (ans.size() < count) {
                    visited[start][j] = false;
                    ans.pop_back();
                 }
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>>graph;
        for (int i = 0; i < tickets.size(); i++) {
            graph[tickets[i][0]].emplace_back(tickets[i][1]);
        }
        int count = 1;
        unordered_map<string, vector<bool>>visited;
        for (auto& it: graph) {
            sort(it.second.begin(), it.second.end());
            count+=it.second.size();
            vector<bool>temp(it.second.size(), false);
            visited[it.first] = temp;
        }
        vector<string>ans;
        ans.emplace_back("JFK");
        go ("JFK", graph, visited, ans, count);
        return ans;
    }
};
//the fatest solution
class Solution {
    unordered_map<string, pair<size_t, vector<string>>> mTickets;
    vector<string> mResult;
        
    void f(const string& from) {
        auto it = mTickets.find(from);
        
        if (it != mTickets.end()) {
            auto& [pos, v] = it->second;
            while (pos != v.size()) {
                ++pos;
                f(v[pos - 1]);
            }
        }
        
        mResult.emplace_back(from);
    }
        
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        mResult.clear();
        
        for (const auto& v: tickets)
            mTickets[v[0]].second.emplace_back(v[1]);
        
        for (auto& [from, p]: mTickets)
            sort(p.second.begin(), p.second.end());
        
        f("JFK");
        reverse(mResult.begin(), mResult.end());
        
        return mResult;
    }
};
