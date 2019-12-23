/*
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:

Input: [[1,1],[-1,1]]
Output: true
Example 2:

Input: [[1,1],[-1,-1]]
Output: false
Follow up:
Could you do better than O(n2) ?

wrong test case:
[[0,0],[1,0],[3,0]]
[[0,0]]
[[1,1],[0,0],[-1,1]]
 */
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        if (points.size() == 1) return true;
        int small = INT_MAX, big = INT_MIN;
        for (int i = 0; i < points.size(); i++) {
            big = max(big, points[i][0]);
            small = min(small, points[i][0]);
        }
        double mid = ((double)big+(double)small)/2;
        vector<bool>used(points.size(), false);
        for (int i = 0; i < points.size(); i++) {
            if (!used[i]) {
                for (int j = 0; j < points.size(); j++) {
                    if (points[i][1] == points[j][1] && mid == ((double)points[i][0]+(double)points[j][0])/2) {
                        used[i] = used[j] = true;
                        break;
                    }  
                }
                if (!used[i]) return false;
            }
        }
        return true;
    }
};
//16 ms solution
struct pair_hash{
    size_t operator()(pair<int,int> const &p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int n = points.size();
        if(!n) return true;
        int lx = points[0][0];
        int hx = points[0][0];
        unordered_set<pair<int,int>, pair_hash> m;
        for(auto& v: points){
            if(v[0] > hx) hx=v[0];
            if(v[0] < lx) lx=v[0];
            m.insert(pair<int,int>(v[0],v[1]));
        }
        int y = hx+lx;
        for(auto& v: points)if(!m.count(pair<int,int>(y-v[0],v[1]))) return false;
        return true;
    }
};
