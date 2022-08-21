class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>>c;
    DetectSquares() {
        //c.clear();
    }
    
    void add(vector<int> point) {
        c[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int ans = 0, s = 1, x, dist;
        //same x
        if (c.count(point[0])) {
            for (auto& it: c[point[0]]) {
                //if (it.first == point[0]) {
                dist = abs(it.first-point[1]);
                if (dist == 0) continue;
                x = point[0]+dist;

                if (c.count(x) && (c[x].count(it.first)
                   && c[x].count(point[1]))) {//right
                    ans+=(s*c[x][it.first]*c[x][point[1]]*it.second);
                }
                x = point[0]-dist;

                if (c.count(x) && (c[x].count(it.first)
                   && c[x].count(point[1]))) {//left
                    ans+=(s*c[x][it.first]*c[x][point[1]]*it.second);
                }
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
