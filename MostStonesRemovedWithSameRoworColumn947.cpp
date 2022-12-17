class Solution {
public:
    int ans = 0;
    unordered_set<int>pick;
    void go (int start, vector<bool>& used, vector<vector<int>>& points) {
        if (used[start]) return;
        if (!pick.count(start)) {
            used[start] = true;
            ans++;
        }
        
        for (int i : points[start]) go (i, used, points);
    }
    int removeStones(vector<vector<int>>& stones) {
        int len = stones.size(), big = 0, index = -1;
        vector<vector<int>>points(len);
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    points[i].push_back(j);
                    points[j].push_back(i);
                }
            }
        }
        vector<pair<int, int>>ps;
        for (int i = 0; i < len; i++) {
            ps.push_back({points[i].size(),i});
        }
        vector<bool>used(len, false);
        sort(ps.begin(), ps.end());
        
        for (int i = len-1; i > 0; i--) {
            if (!used[ps[i].second]) {
                pick.insert(ps[i].second);
                go (ps[i].second, used, points);
            }
        }
        return (ans == len)? ans-1: ans;
    }
};
