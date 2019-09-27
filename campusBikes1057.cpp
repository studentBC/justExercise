class Solution {
public:
    static bool compare (tuple<int, int, int>& a, tuple<int, int, int>& b) {
        if (get<0>(a) == get<0>(b)) {
            if (get<1>(a) == get<1>(b)) {
                return get<2>(a) < get<2>(b);
            } else {
                return get<1>(a) < get<1>(b);
            }
        } else {
            return get<0>(a) < get<0>(b);
        }
    }
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<tuple<int,int,int>>pos;
        for (int i = 0; i < workers.size(); i++) {
            pos.emplace_back(make_tuple( (abs(workers[i][0])+abs(workers[i][1])), 0, i));
        }
        for (int i = 0; i < bikes.size(); i++) {
            pos.emplace_back(make_tuple( (abs(bikes[i][0])+abs(bikes[i][1])) , 1, i));
        }
        sort(pos.begin(), pos.end(), compare);
        /*
        for (int i = 0; i < pos.size(); i++) {
            cout << get<0>(pos[i]) <<" , " << get<1>(pos[i]) <<" , " << get<2>(pos[i]) << endl;
        }*/

        vector<bool>visited(pos.size(), false);
        vector<int>ans(workers.size(), -1);
        int count = workers.size(), len, cw, cb,shortest, a, b;

        while (count) {
            shortest = INT_MAX;
            for (int i = 0; i < pos.size(); i++) {
                if (!visited[i] && get<1>(pos[i]) == 0) {
                    for (int j = 0; j < pos.size(); j++) {
                        if (!visited[j] && get<1>(pos[j]) == 1 && abs(get<0>(pos[i])-get<0>(pos[j])) < shortest) {
                            len = abs(workers[get<2>(pos[i])][0] - bikes[get<2>(pos[j])][0]) +  abs(workers[get<2>(pos[i])][1] - bikes[get<2>(pos[j])][1]);
                            if (shortest > len) {
                                shortest = len;
                                cw = get<2>(pos[i]);cb = get<2>(pos[j]);
                                a = i; b = j;
                            } else if (shortest == len) {
                                if (cw > get<2>(pos[i])) {
                                    cw = get<2>(pos[i]);cb = get<2>(pos[j]);
                                    a = i; b = j;
                                } else if (cw == get<2>(pos[i])) {
                                    if (cb > get<2>(pos[j])) {
                                        cw = get<2>(pos[i]);cb = get<2>(pos[j]);
                                        a = i; b = j;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            visited[a] = visited[b] = true;
            //cout <<"worker: " << cw << " bike: " << cb << endl;
            ans[cw] = cb;
            count--;
        }

        return ans;
    }
};
//20 ms solution
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        const int N = workers.size();
        const int M = bikes.size();
        bool assigned_worker[N] = {};
        bool assigned_bikes[M] = {};
        vector<int> assign(N);
        vector<tuple<int,int,int>> s;
        int dist[N][M];
        for (int i = 0;i < N; ++i)
        {
            int minimizer = 0;
            int min_dis = dist[i][0] = abs(workers[i][0] - bikes[0][0]) + abs(workers[i][1] - bikes[0][1]);
            for (int j = 1;j < M; ++j)
            {
                dist[i][j] = (int)(abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]));            
                if (dist[i][j] < min_dis)
                {
                    min_dis = dist[i][j];
                    minimizer = j;
                }                
            }    
            s.push_back({i,minimizer,min_dis});
        }
        
        for (int i = 0;i < N; ++i)
        {
            int best_match = get<0>(s[0]);
            int best_dis = get<2>(s[0]);
            int best_idx = 0;
            for (int j = 1;j < N - i; ++j)
            if (get<2>(s[j]) < best_dis)
            {
                best_match = get<0>(s[j]);
                best_dis = get<2>(s[j]);
                best_idx = j;
            }
            int bike_to_assign = get<1>(s[best_idx]);
            assign[best_match] = bike_to_assign;
            
            assigned_worker[best_match] = assigned_bikes[bike_to_assign] = true;
            
            s.erase(s.begin()+best_idx);
            for (int j = 0; j < N - i -1; ++j)
                if (get<1>(s[j]) == bike_to_assign)
                {
                    int worker_idx = get<0>(s[j]);
                    int minimizer = -1;
                    int min_dis = -1;
                    for (int j = 0;j < M; ++j)
                    if (!assigned_bikes[j])
                    {                        
                        if (min_dis == -1 || dist[worker_idx][j] < min_dis)
                        {
                            min_dis = dist[worker_idx][j];
                            minimizer = j;
                        }                        
                    }
                    s[j] = make_tuple(worker_idx,minimizer,min_dis);
                }            
        }
        return assign;
    }
};
/*concept solution
Since the range of distance is [0, 2000] which is much lower than the # of pairs, which is 1e6. It's a good time to use bucket sort. Basically, it's to put each pair into the bucket representing its distance. Eventually, we can loop thru each bucket from lower distance.
Therefore, it's O(M * N) time and O(M * N) space. Only takes 60 ms in C++ beat most submissions.
See the code:*/

class Solution {
public:
    // bucket sort
    // O(N*M) time, O(N*M) space
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // bucket sort since range of distance is [0, 2000]
        vector<vector<pair<int, int>>> buckets(2001); // buckets[i] is the vector<worker id, bike id> with distance i
        int n = workers.size(), m = bikes.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                buckets[dis].push_back({i, j});
            }
        }
        vector<int> res(n, -1);
        vector<bool> bikeUsed(m, false);
        for (int d = 0; d <= 2000; d++) {
            for (int k = 0; k < buckets[d].size(); k++) {
                if (res[buckets[d][k].first] == -1 && !bikeUsed[buckets[d][k].second]) {
                    bikeUsed[buckets[d][k].second] = true;
                    res[buckets[d][k].first] = buckets[d][k].second;
                }
            }
        }
        return res;
    }
};
