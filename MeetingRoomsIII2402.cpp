class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, long long>, std::vector<pair<long long, long long>>, std::greater<pair<long long, long long>>>pq;
        priority_queue<int, vector<int>, greater<int>>available;
        vector<int>count(n, 0);
        int idx = 0, big = 0, ans = INT_MAX;
        for (int i = 0; i < n; i++) available.push(i);
        for (auto& it: meetings) {
            while (!pq.empty() && pq.top().first <= it[0]) {
                available.push(pq.top().second);
                pq.pop();
            }
            if (!available.empty()) {
                idx = available.top();
                available.pop();
                pq.push({it[1], idx});
                count[idx]++;
            } else {
                idx = pq.top().second;
                pq.push({pq.top().first + it[1]-it[0], idx});
                pq.pop();
                count[idx]++;  
            }
            if (count[idx] == big) {
                ans = min(idx, ans);
            } else if (count[idx] > big) {
                big = count[idx];
                ans = idx;
            }
        }
        return ans;
    }
};
