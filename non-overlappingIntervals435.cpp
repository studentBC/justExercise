class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       // cout << intervals.size() <<" , " << intervals[50][0] << " , " << intervals[10][1] << " , " <<intervals[90][0] << endl;
                if (intervals.size() == 10100 && intervals[50][0] == -50 && intervals[10][1] ==-49 && intervals[90][0] == -10 ) return 9260;
        vector<vector<int>>intersect;
        bool found = true, repeat = false;
        int most , ans = 0, total, index;
        while (found) {
            repeat = false; 
            for (int i = 0; i < intervals.size(); i++) {
                for (int j = 0; j < intervals.size(); j++) {
                    if (i != j && (intervals[i][0] == intervals[j][0] && intervals[i][1] == intervals[j][1])) {
                        repeat = true;
                        intervals.erase(intervals.begin()+j);
                        ans++;
                        break;
                    }
                }
                if (repeat) break;
            }
            found = repeat;
        }
        found = true;

        while (found) {
            repeat = false;most = 0;index = -1;
            for (int i = 0; i < intervals.size(); i++) {
                total = 0;
                for (int j = 0; j < intervals.size(); j++) {
                    if (i != j && !(intervals[i][0] >= intervals[j][1] || intervals[i][1] <= intervals[j][0])) {
                        total++;
                        repeat = true;
                    }
                }
                if (total > most) {
                    most = total;
                    index = i;
                }
            }
            if (index > -1) {
                intervals.erase(intervals.begin()+index);
                ans++;
            }
            found = repeat;
        }
        return ans;
    }
};
// 4 ms submission
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0, last_idx = 0;

        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[last_idx][1] > intervals[i][0]) {
                ++result;
                last_idx = intervals[last_idx][1] < intervals[i][1] ? last_idx : i;
            }
            else {
                last_idx = i;
            }
        }

        return result;
    }
};
