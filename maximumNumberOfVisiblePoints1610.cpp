#define margin 1e-9
#define pi 3.1415926
class Solution {
public:
    double getAngle(int x, int y) {
        return atan2(y, x)*180/pi;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int len = points.size(), same = 0, x, y;
        vector<double>angles;
        for (int i = 0; i < len; i++) {
            x = points[i][0] - location[0];
            y = points[i][1] - location[1];
            if (!x && !y) same++;
            else {
                double a = getAngle(x, y);
                if (a < 0) a+=360;
                angles.push_back(a);
            }
        }
        sort(angles.begin(), angles.end());
        vector<double>ra = angles;
        ra.insert(ra.begin(), angles.begin(), angles.end());
        for (int i = angles.size(); i < ra.size(); i++) ra[i]+=360;
        int ans = 0;
        angle+=margin;
        for (int i = 0, j = 0; i < ra.size(); i++) {
            while (j < ra.size() && (ra[j]-ra[i] <= angle)) j++;
            ans = max(ans, j-i);
        }
        return ans+same;

    }
};
