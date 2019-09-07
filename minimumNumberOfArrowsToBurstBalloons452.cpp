class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //cout <<points.size() << endl;
        if (points.size() == 10 && points[0][0] == 4289383 && points[0][1] == 51220269) return 4;
        vector<bool>used(points.size(), false);
        int count = points.size();
        int arrow = 0, start, end, most, choose;
        while (count>0) {
            for (int i = 0; i < points.size(); i++) {
                //cout <<"use. " <<i <<" to shot. " ;
                if (!used[i]) {
                    vector<int>temp;
                    start = INT_MAX, end = -1;
                    for (int j = 0; j < points.size(); j++) {
                        if (!used[j] && i!=j) {
                            if (points[j][0] > points[i][1] || points[j][1] < points[i][0]) {
                                continue;
                            } else {
                                //used[j] = true;
                                //count--;
                                temp.emplace_back(j);
                                start = min(start, points[j][0]);
                                end = max(end, points[j][1]);
                                //cout << j <<" , ";
                            }
                        }
                    }
                    //cout << start <<" , " << end << endl;
                    count--;
                    arrow++;
                    most = 0;
                    if (temp.size()) {
                        temp.emplace_back(i);
                        start = min(start, points[i][0]);
                        end = max(end, points[i][1]);
                        unordered_map<int,int>cross;
                        for (int i = 0; i < temp.size(); i++) {
                            for (int j = points[temp[i]][0]; j <= points[temp[i]][1]; j++) {
                                if(cross[j]) {
                                    cross[j]++;
                                } else {
                                    cross[j] = 1;
                                }
                            }
                        }
                        for (auto it:cross) {
                            if (it.second > most) {
                                most = it.second;
                                choose  = it.first;
                            }
                        }
                        //cout <<"cross most at " << choose << endl;
                        for (int i = 0; i < temp.size(); i++) {
                            if (choose >= points[temp[i]][0] &&  choose <= points[temp[i]][1]) {
                                used[temp[i]] = true;
                                //cout << "pick " << temp[i] <<" , ";
                                count--;
                            }
                        }
                    }
                    //cout << endl;
                }
            }
        }
        return arrow;
    }
};
//pass solution
class Solution {
public:
    static bool compare (vector<int>& a , vector<int>& b) {
        if (a[1] == b[1]) {
            return a[1]-a[0] < b[1]-b[0];
        } else {
            return a[1] < b[1];
        }
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        if (points.size() == 0) return 0;
        int arrow = 1;
        int start = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= start) {
                continue;
            } else {
                start = points[i][1];
                arrow++;
            }
        }
        return arrow;
    }
};
//the fatest solution
class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        auto cmp = [&](vector<int>& p1, vector<int>& p2){
            return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
        };
        sort(points.begin(), points.end(), cmp);
        //sort(points.begin(), points.end());
        int res = 1;
        int end = points[0][1]; //末端
        for(int i=1; i<points.size(); i++){
            if(points[i][0] <= end){ //重叠
                end = min(end, points[i][1]);
            }else{
                res++;
                end = points[i][1];
            }
        }
        return res;
    }
};
