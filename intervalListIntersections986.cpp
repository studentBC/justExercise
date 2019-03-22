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
    int containPart (vector<Interval>& A, int point) {
        for (int i = 0; i < A.size(); i++) {
            if (A[i].start <= point && A[i].end >= point) {
                return i;
            }
        }
        return -1;
    }
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<int>points;
        set<int>p;
        for (int i = 0; i < A.size(); i++) {
            p.insert(A[i].start);
            p.insert(A[i].end);
        }
        for (int i = 0; i < B.size(); i++) {
            p.insert(B[i].start);
            p.insert(B[i].end);
        }
        for (auto it = p.begin(); it!=p.end(); it++) points.push_back(*it);
        sort(points.begin(),points.end());
        int a, b, a2, b2, end = points.size()-1;
        vector<Interval>ans;
        for (int i = 0; i < end; i++) {
            //cout << points[i] << endl;
            a = containPart(A,points[i]);
            b = containPart(B,points[i]);
            if (a > -1 && b > -1) {
                a2 = containPart(A,points[i+1]);
                b2 = containPart(B,points[i+1]);
                //cout << points[i] << " , ";
                if ( a2 == a && b2 == b) {
                    ans.push_back(Interval(points[i],points[i+1]));
                    i++;
                } else {
                    ans.push_back(Interval(points[i],points[i]));
                }
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> result;
        for(int i = 0, j = 0; i < A.size() && j < B.size();) {
            if (A[i].end < B[j].start) 
                ++i;
            else if (B[j].end < A[i].start) 
                ++j;
            else {
                result.push_back({max(A[i].start, B[j].start), min(A[i].end, B[j].end)});
                if (A[i].end < B[j].end) ++i;
                else ++j;   
            }
        }
        return result;
    }
};

