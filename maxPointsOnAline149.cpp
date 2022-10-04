/*
A line is determined by two factors,say y=ax+b
If two points(x1,y1) (x2,y2) are on the same line(Of course). 

Consider the gap between two points.
We have (y2-y1)=a(x2-x1),a=(y2-y1)/(x2-x1) a is a rational, b is canceled since b is a constant
*/
class Solution {
public:
    int getGCD (int a, int b) {
        return b == 0? a: getGCD(b, a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size(), ans = 0, overlap = 0, big = 0, x, y;
        if (points.size() < 3) return len;
        unordered_map<int, unordered_map<int, int>>mp;
        for (int i = 0; i < len; i++) {
            overlap = big = 0;
            mp.clear();
            for (int j = i+1; j < len; j++) {
                x = points[j][0] - points[i][0];
                y = points[j][1] - points[i][1];
                if (x == 0 && y == 0) {
                    overlap++;
                    continue;
                }
                int gcd = getGCD(x, y);
                if (gcd) {
                    x/=gcd;
                    y/=gcd;
                }
                mp[x][y]++;
                big = max(big, mp[x][y]);
            }
            ans = max(ans, big+overlap);
        }
        return ans+1;
    }
};
