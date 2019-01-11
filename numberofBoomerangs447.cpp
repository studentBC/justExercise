class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        map<int,int>dist;
        int key , count = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                key = pow((points[i].first - points[j].first), 2) + pow((points[i].second - points[j].second), 2);
                if (dist.find(key)==dist.end()) {
                    dist.insert(dist.begin() , pair<int,int>(key,1));
                } else {
                    dist.find(key)->second++;
                }
            }
            for (auto it = dist.begin(); it!=dist.end(); it++) {
                if (it->second>=2) {
                    count+=(it->second*(it->second-1));
                }
            }
            dist.clear();
        }
        return count;
    }
};

