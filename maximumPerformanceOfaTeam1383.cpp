class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>worker;
        for (int i = 0; i < speed.size(); i++) {
            worker.push_back(make_pair(efficiency[i], speed[i]));
        }
        sort (worker.begin(), worker.end());
        priority_queue<int, vector<int>, greater<int>>pq;
        long sum = 0, ans = 0;
        for (int i = n-1; i > -1; i--) {
            pq.push(worker[i].second);
            sum+=worker[i].second;
            if (pq.size() > k) {
                sum-=pq.top();
                pq.pop();
            }
            ans = max (ans, sum*worker[i].first);
        }
        return ans%(int)(1e9+7);
    }
};
//the fatest solution
class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        vector<pair<int, int>> eff_sp;
        priority_queue<int, vector<int>, greater<int> > pq_speeds;
        long sum = 0, res = 0;
        for (auto i = 0; i < n; ++i)
            eff_sp.push_back({efficiency[i], speed[i]});
        sort(begin(eff_sp), end(eff_sp));
        for (auto i = n - 1; i >= 0; --i) {
            sum += eff_sp[i].second;
            pq_speeds.push(eff_sp[i].second);
            if (pq_speeds.size() > k) {
                sum -= pq_speeds.top();
                pq_speeds.pop();
            }
            res = max(res, sum * eff_sp[i].first);
        }
        return res % 1000000007;
    }
};
