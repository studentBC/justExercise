/*
we are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
 

Example 2:

Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
 

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined.)

	Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

	Note:

	schedule and schedule[i] are lists with lengths in range [1, 50].
	0 <= schedule[i].start < schedule[i].end <= 10^8.
	NOTE: input types have been changed on June 17, 2019. Please reset to default code definition to get new method signature.
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

merge interval concept:
https://www.geeksforgeeks.org/merging-intervals/
*/
class Solution {
public:
    static bool compare (Interval* a, Interval* b) {
        return a->start < b->start;
    }
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>>& schedule) {
        vector<Interval*>workers, wt, ans;
        for (int i = 0; i < schedule.size(); i++) { 
            for (int j = 0; j < schedule[i].size(); j++) {
                workers.emplace_back(schedule[i][j]);
            }
        }
        sort(workers.begin(), workers.end(), compare);
        wt.emplace_back(workers[0]);
        for (int i = 1; i < workers.size(); i++) {
            if (wt.back()->end < workers[i]->start) {
                wt.emplace_back(workers[i]);
            } else {
                wt.back()->end = max(workers[i]->end, wt.back()->end);
            }
        }
        int end = wt.size()-1;
        for (int i = 0; i < end; i++) {
            Interval* temp = new Interval(wt[i]->end, wt[i+1]->start);
            ans.emplace_back(temp);
        }
        return ans;
    }
};

//284 ms solution
static int fast_io = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>>& schedule) {
        vector<int> starts;
        vector<int> ends;
        vector<Interval*> res;
        
        for (auto& employee : schedule)
        {
            for (auto& segment : employee)
            {
                starts.push_back(segment->start);
                ends.push_back(segment->end);
            }
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        
        vector<pair<int,int>> vec;
        int count=0, i=0, j=0;
        while (i<starts.size() && j<ends.size()) {     
            if (starts[i]<ends[j]) {
                count++;
                i++;
            } else if (starts[i]==ends[j]) {
                i++;
                j++;
            } else {
                if (--count==0) {
                    res.push_back(new Interval(ends[j],starts[i]));
                }
                j++;
            }
                
        }
        
        return res;
            
    }
};

