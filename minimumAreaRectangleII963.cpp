class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int len = points.size();
        if (len < 4) return 0;
        double ans = INT_MAX, centerx, centery, dist, area;
        unordered_map<string, vector<vector<int>>>mp;
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                dist = pow(points[i][0]-points[j][0], 2) + pow(points[i][1]-points[j][1], 2);
                centerx = (double)(points[i][0]+points[j][0])/2;
                centery = (double)(points[i][1]+points[j][1])/2;
                string key = to_string(dist) + " "+to_string(centerx) + " " + to_string(centery);
                mp[key].push_back({i, j});
            }
        }
        double l1, l2;
        int p1, p2, p3;
        for (auto& it: mp) {
            if (it.second.size() > 1) {
                for (int i = 0; i < it.second.size(); i++) {
                    for (int j = i+1; j < it.second.size(); j++) {
                        area = l1*l2;
                        p1 = it.second[i][0];
                        p2 = it.second[j][0];
                        p3 = it.second[j][1];
                        l1 = sqrt(pow(points[p1][0]-points[p2][0], 2) + pow(points[p1][1]-points[p2][1], 2));
                        l2 = sqrt(pow(points[p1][0]-points[p3][0], 2) + pow(points[p1][1]-points[p3][1], 2));
                        area = l1*l2;
                        ans = min(ans, area);
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
