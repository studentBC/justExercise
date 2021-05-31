class Solution {
public:
    typedef pair<long long, int> pd;
    static bool compare (pair<int,int>& a, pair<int,int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<pair<int,int>>index;
        vector<int>ans, time(tasks.size(), 0);
        int it;
        for (int i = 0; i < servers.size(); i++) index.push_back(make_pair(servers[i], i));
        sort(index.begin(), index.end(), compare);
        priority_queue<pd, vector<pd>, myComp> uav;
        priority_queue<int, vector<int>,  greater<int> >av;
        //priority_queue<pd, vector<pd>, myComp> uav;
        for (int i = 0; i < index.size(); i++) {
            av.push(i);
        }
        int ct = 0;
        for (int i = 0; i < tasks.size(); i++) {
            while (!uav.empty() && uav.top().first <= ct) {
                av.push(uav.top().second);
                uav.pop();
            }
            if (av.empty()) {
                it = uav.top().second;
                ans.push_back(index[uav.top().second].second);
                ct = uav.top().first;
                uav.pop();
                uav.push(make_pair(ct+tasks[i], it));
            } else {
                ans.push_back(index[av.top()].second);
                it = av.top();
                av.pop();
                uav.push(make_pair(ct+tasks[i], it));
                if (ct <= i) ct = i+1;
            }

        }
        return ans;
    }
};
//the 312 ms solution
typedef pair<long, int> pii;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size(), i = 1;
        while(i < m && tasks[i] == tasks[i-1]){
            i++;
        }
        if(i == m){
            // all same
            vector<pii> serverIdx;
            for(int i = 0; i < n; i++){
                serverIdx.emplace_back(servers[i], i);
            }
            sort(serverIdx.begin(), serverIdx.end());
            vector<int> ans(m, 0);
            for(int i = 0; i < m; i++){
                ans[i] = serverIdx[i%min(n, tasks[0])].second;
            }
            return ans;
        }
        auto comp = [&](int i, int j){return servers[i] == servers[j] ? i > j : servers[i] > servers[j];};
        priority_queue<int, vector<int>, decltype(comp)> freeServers(comp);
        for(int i = 0; i < n; i++){
            freeServers.push(i);
        }
        priority_queue<pii, vector<pii>, greater<pii>> freeAt;
        vector<int> ans(m, -1);
        long t = 0;
        int j = 0; // task id
        while(j < m){
            while(!freeAt.empty() && freeAt.top().first <= t){
                freeServers.push(freeAt.top().second);
                freeAt.pop();
            }
            while(j <= t && !freeServers.empty()){
                int idx = freeServers.top();
                freeServers.pop();
                ans[j] = idx;
                freeAt.emplace(t+tasks[j], idx);
                j++;
            }
            if(freeServers.empty()){
                t = freeAt.top().first;
            }else{
                t++;
            }
        }
        return ans;
    }
};
