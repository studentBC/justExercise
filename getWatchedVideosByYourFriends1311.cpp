class Solution {
public:

    static bool compare(pair<int, string>& a, pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int>next;
        unordered_set<int>visited;
        next.push(id);
        visited.insert(id);
        for (int i = 0; i < level; i++) {
            queue<int>temp;
            while (!next.empty()) {
                id = next.front();
                next.pop();
                for (int j = 0; j < friends[id].size(); j++) {
                    if (!visited.count(friends[id][j])) {
                        temp.push(friends[id][j]);
                        visited.insert(friends[id][j]);
                    }
                }
            }
            next = temp;
        }
        unordered_map<string, int>tmp;
        while (!next.empty()) {
            for (string s: watchedVideos[next.front()]) {
                tmp[s]++;
            }
            next.pop();
        }
        vector<pair<int, string>>outcome;
        vector<string>ans;
        for (auto& it: tmp) {
            outcome.push_back(make_pair(it.second, it.first));
        }
        sort(outcome.begin(), outcome.end(), compare);
        for (auto& it: outcome) {
            ans.push_back(it.second);
        }
        return ans;
    }

};
//the fatest solution
class Solution {
public:
    map < string, int > M;
    vector < int > vis;
    vector<string> watchedVideosByFriends(vector<vector<string>>& vid, vector<vector<int>>& adj, int id, int level) {
        int n = adj.size();
        vis.resize(n + 5, -1);
        queue < int > q;
        q.push(id);
        vis[id] = 0;
        while(!q.empty()) {
            int temp = q.front();       q.pop();
            for(int i = 0;i < adj[temp].size();++i) {
                int to = adj[temp][i];
                if(vis[to] == -1) {
                    vis[to] = vis[temp] + 1;
                    if(vis[to] == level) {
                        for(int j = 0;j < vid[to].size();++j) {
                            string v = vid[to][j];
                            M[v]++;
                        }
                    }
                    q.push(to);
                }
            }
        }
        
        vector < pair < string, int > > ret;
        for(auto it = M.begin();it != M.end();++it) {
            ret.push_back({it -> first, it -> second});
            // cout << it -> first << "  " << it -> second << "\n";
        }
        sort(ret.begin(), ret.end(), [](pair < string, int > &a, pair < string, int > &b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        vector < string > ans;
        for(int i = 0;i < ret.size();++i) {
            ans.push_back(ret[i].first);
        }
        return ans;
    }
};
