class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int lx = INT_MAX, ly = INT_MAX, rx = INT_MIN, ry = INT_MIN, area = 0;
        unordered_set<string>point;
        for (int i = 0; i < rectangles.size(); i++) {
            lx = min (lx, rectangles[i][0]);
            rx = max (rx, rectangles[i][2]);
            ly = min (ly, rectangles[i][1]);
            ry = max (ry, rectangles[i][3]);
            string a = to_string(rectangles[i][0])+","+ to_string(rectangles[i][1]);
            if (point.count(a)) point.erase(a);
            else point.insert(a);
            string b = to_string(rectangles[i][0])+","+ to_string(rectangles[i][3]);
            if (point.count(b)) point.erase(b);
            else point.insert(b);
            string c = to_string(rectangles[i][2])+","+ to_string(rectangles[i][1]);
            if (point.count(c)) point.erase(c);
            else point.insert(c);
            string d = to_string(rectangles[i][2])+","+ to_string(rectangles[i][3]);
            if (point.count(d)) point.erase(d);
            else point.insert(d);
            area += ((rectangles[i][2]-rectangles[i][0])*(rectangles[i][3]-rectangles[i][1]));
        }
            string a = to_string(lx)+","+ to_string(ly);
            string b = to_string(lx)+","+ to_string(ry);
            string c = to_string(rx)+","+ to_string(ly);
            string d = to_string(rx)+","+ to_string(ry);
        if (point.size() == 4 && point.count(a) && point.count(b) && point.count(c) && point.count(d) && area == (rx-lx)*(ry-ly) ) return true;
        return false;
    }
};
//the fatest solution
class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.empty() || rectangles[0].empty()) return false;
        unordered_set<ulong> st;
        int min_x = INT_MAX, min_y = INT_MAX;
        int max_x = INT_MIN, max_y = INT_MIN, area = 0;
        for(auto& rect : rectangles) {
            min_x = min(min_x, rect[0]);
            min_y = min(min_y, rect[1]);
            max_x = max(max_x, rect[2]);
            max_y = max(max_y, rect[3]);
            area += (rect[3]-rect[1])*(rect[2]-rect[0]);
            ulong l = (((ulong)(unsigned)rect[0])<<32) | (unsigned)rect[1];
            ulong u = (((ulong)(unsigned)rect[0])<<32) | (unsigned)rect[3];
            ulong r = (((ulong)(unsigned)rect[2])<<32) | (unsigned)rect[3];
            ulong d = (((ulong)(unsigned)rect[2])<<32) | (unsigned)rect[1];
            if(st.count(l)) st.erase(l);
            else st.insert(l);
            if(st.count(u)) st.erase(u);
            else st.insert(u);
            if(st.count(r)) st.erase(r);
            else st.insert(r);
            if(st.count(d)) st.erase(d);
            else st.insert(d);
        }
        ulong t1 = (((ulong)(unsigned)min_x)<<32) | (unsigned)min_y;
        ulong t2 = (((ulong)(unsigned)min_x)<<32) | (unsigned)max_y;
        ulong t3 = (((ulong)(unsigned)max_x)<<32) | (unsigned)max_y;
        ulong t4 = (((ulong)(unsigned)max_x)<<32) | (unsigned)min_y;
        if (!st.count(t1) || !st.count(t2) || !st.count(t3) || !st.count(t4) || st.size() != 4) 
            return false;
    
        return area == (max_y-min_y)*(max_x-min_x);
    }
}; 
