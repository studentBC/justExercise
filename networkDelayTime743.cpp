//using dijkstra algs pls refer to https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
class Solution {
public:
    int choose (vector<int>&dis, bool* point) {
        int longest = INT_MAX, index;
        for (int i = 0; i < dis.size(); i++) {
            if (!point[i] && dis[i] < longest ) {
                longest = dis[i];
                index = i;
            }
        }
        return index;
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        bool point[N] = {false};
        vector<int>dis;
        int count = N, start, ans = 0;
        for (int i = 0; i < N; i++) {
            if (i+1 == K) {
                dis.emplace_back(0);
            } else {
                dis.emplace_back(INT_MAX);
            }
        }
        while (count) {
            start = choose(dis, point);
            //cout <<start <<" , ";
            for (int i = 0; i < times.size(); i++) {
                if (times[i][0] == start+1) {
                    if (dis[times[i][1]-1] > times[i][2]+dis[start]) {
                        dis[times[i][1]-1] = times[i][2]+dis[start];
                    }
                }
            }
            point[start] = true;
            count--;
        }
        for (int i:dis) {
            //cout << i << " , ";
            ans = max(ans, i);
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
//48 ms solution
static auto x = []()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dis(N+1,INT_MAX);
        vector<int> vis(N+1,false);
        dis[K]=0;
        vector<vector<pair<int,int>>> graph(N+1);
        for(int i=0;i<times.size();i++)
        {
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        set<pair<int,int>> s;
        s.insert({0,K});
        while(!s.empty())
        {
            pair<int,int> p = *s.begin();
            s.erase(s.begin());
            vis[p.second]=true;
            for(int i=0;i<graph[p.second].size();i++)
            {
                int a = graph[p.second][i].first;
                if(vis[a])
                {
                    continue;
                }
                int b = graph[p.second][i].second;
                if(dis[a]>p.first+b)
                {
                    if(s.find({dis[a],a})!=s.end())
                    {
                        s.erase({dis[a],a});
                    }
                    dis[a]=p.first+b;
                    s.insert({dis[a],a});
                }
            }
        }
        int ans=0;
        for(int i=1;i<dis.size();i++)
        {
            ans = max(ans,dis[i]);
            if(dis[i]==INT_MAX)
            {
                return -1;
            }
        }
        return ans;
    }
};
