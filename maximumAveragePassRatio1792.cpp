/*
Since the change in the pass ratio is always decreasing with the more students you add, then the very first student you add to each class is the one that makes the biggest change in the pass ratio.
Because each class's pass ratio is weighted equally, it's always optimal to put the student in the class that makes the biggest change among all the other classes.
*/


class Solution {
public:
    
    struct myComp { 
        constexpr bool operator()( 
            pair<double, double> const& a, 
            pair<double, double> const& b) 
            const noexcept 
        { 
            double da = a.first/a.second, db = b.first/b.second;
            return ((a.first+1)/(a.second+1)-da) < ((b.first+1)/(b.second+1)-db); 
        } 
    };
    /*static bool compare (pair<double,double>& a, pair<double,double>& b) {
        double da = a.first/a.second, db = b.first/b.second;
        return (a.first+1)/(a.second+1)-da > (b.first+1)/(b.second+1)-db;
    }*/
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, double>, vector<pair<double,double>>, myComp>pq;
        double ans = 0, count = 0;
        for (auto& it: classes) {
            pq.push(make_pair(it[0], it[1]));
        }
        while (extraStudents) {
            pair<double, double>f = pq.top();
            f.first++; f.second++;
            pq.pop();
            pq.push(f);
            extraStudents--;
        }
        while (!pq.empty()) {
            pair<double, double>f = pq.top();
            ans+=(f.first/f.second);
            //cout << f.first <<" , " << f.second << endl;
            pq.pop();
            count++;
        }
        return ans/count;
    }
};
