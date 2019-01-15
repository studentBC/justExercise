/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool compare (pair<Interval ,int> a, pair<Interval ,int> b) {
        return a.first.start < b.first.start;
    }
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int>ans;
        bool found = true;
        vector<pair<Interval ,int>>temp;
        for (int i = 0; i < intervals.size(); i++) {
            temp.push_back(make_pair(intervals[i],i));
        }
        sort(temp.begin(), temp.end(), compare);
        for (int i = 0; i < intervals.size(); i++) {
            //cout << intervals[i].start << " , " << intervals[i].end << endl;
            found = true;
            for (int j = 0; j < intervals.size(); j++) {
                if (intervals[i].end <= temp[j].first.start) {
                    ans.push_back(temp[j].second);
                    //temp[j].first.start = INT_MIN;
                    found = false;
                    break;
                }
            }
            if (found) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int fm(int target, vector<pair<int, int>>& A) {
        int lo = 0;
        int hi = int(A.size()) - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid].first < target) {
                lo = mid + 1;
            } else if (mid == 0 || A[mid - 1].first < target) {
                return A[mid].second;
            } else {
                hi = mid;
            }
        }
        
        return -1;
    }
    
    
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> res;
        vector<pair<int, int>> starts;
        int N = intervals.size();
        for (int i = 0; i < N; i++) {
            starts.push_back({intervals[i].start, i});
        }
        sort(starts.begin(), starts.end());
        
        for (int i = 0; i < N; i++) {
            int f = fm(intervals[i].end, starts);
            res.push_back(f);
        }
        
        return res;
    }
};
