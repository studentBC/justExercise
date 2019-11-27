class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX;
        set<pair<int,int>>point;
        for (int i = 0; i < points.size(); i++) {
            point.insert(make_pair(points[i][0], points[i][1]));
        }
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (points[i][0]!=points[j][0] && points[i][1] != points[j][1]) {
                    if (point.count(make_pair(points[i][0],points[j][1])) && point.count(make_pair(points[j][0],points[i][1]))) {
                        ans = min (ans, abs(points[i][0] - points[j][0])*abs(points[i][1] - points[j][1]));
                    }
                }
            }
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};
//the fatest solution
static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> m;
        int res = INT_MAX, i ,j, fLen, sLen, last, t;
        for (vector<int> &point : points) m[point[0]].push_back(point[1]);
        for (unordered_map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++) sort(it->second.begin(), it->second.end());
        for (unordered_map<int, vector<int>>::iterator f = m.begin(); f != m.end(); f++) {
            if (f->second.size() == 1) continue;
            for (unordered_map<int, vector<int>>::iterator s = next(f); s != m.end(); s++) {
                if (s->second.size() == 1) continue;
                i = j = 0, last = -1, fLen = f->second.size(), sLen = s->second.size();
                while (i < fLen && j < sLen) {
                    if (f->second[i] < s->second[j]) i++;
                    else if (f->second[i] > s->second[j]) j++;
                    else {
                        if (last >= 0) {
                            t = abs(s->first - f->first) * (f->second[i] - last);
                            if (res > t) res = t;
                        }
                        last = f->second[i++], j++;
                    }
                }
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};
