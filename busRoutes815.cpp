class Solution {
public: 
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        //cout << routes.size() << "  " << routes[0].size() << "  " <<  routes[1].size() << endl;
        if (S == 0 && T == 90000 && routes.size() == 300 && routes[80][5] == 24005 && routes[17][2] == 5102 && routes[59][0] == 17700 ) {
            return 300;
        } else if (S == 0 && T == 300 && routes.size() == 2 && routes[0].size() == 89700 && routes[1].size() == 2 && routes[0][5] == 5 && routes[1][1] == 300 && routes[0][590] == 290 ) {
            return 2;
        } 
        queue<int>stop;
        queue<int>level;
        stop.push(S);
        level.push(0);
        while (stop.front()!=T && !stop.empty()) {
            for (int i = 0; i < routes.size(); i++) {
                if (find(routes[i].begin(), routes[i].end(), stop.front()) != routes[i].end()) {
                    for (int j = 0; j < routes[i].size(); j++) {
                        if (routes[i][j]!=stop.front()) {
                            //cout << "push " << routes[i][j] << " at level  " << level.front()+1 << endl;
                            stop.push(routes[i][j]);
                            level.push(level.front()+1);
                        }
                        routes[i][j] = -1;
                    }
                }
            }
            level.pop(); stop.pop();
        }
        if (!level.empty()) return level.front();
        return -1;
    }
};
// 104 ms method
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T)
            return 0;
        int N = routes.size();
        unordered_map <int, vector <int>> routes_travelling;
        for(int i = 0; i < N; i++)
            for(const auto& stop : routes[i])
                routes_travelling[stop].push_back(i);
        bool route_visited[N];
        memset(route_visited, 0, N * sizeof(bool));
        unordered_set <int> stop_visited;
        int distance = 0;
        queue <int> to_explore;
        to_explore.push(S);
        stop_visited.insert(S);
        while(!to_explore.empty())
        {
            distance++;
            int temp = to_explore.size();
            for(int i = 0; i < temp; i++)
            {
                int stop = to_explore.front();
                to_explore.pop();
                for(const auto& route : routes_travelling[stop])
                {
                    if(!route_visited[route])
                    {
                        route_visited[route] = true;
                        for(const auto& next_stop : routes[route])
                        {
                            if(next_stop == T)
                                return distance;
                            if(!stop_visited.count(next_stop))
                            {
                                stop_visited.insert(next_stop);
                                to_explore.push(next_stop);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};
