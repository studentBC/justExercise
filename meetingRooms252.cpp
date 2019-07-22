/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); i++) {
            for (int j = i+1; j < intervals.size(); j++) {
                if (intervals[i][0] >= intervals[j][1] || intervals[i][1] <= intervals[j][0]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
//the fatest method
class Solution {
public:
    
    struct less_than_key
{
    inline bool operator() (const vector<int>& arr1, const vector<int>& arr2)
    {
        return (arr1[1] <= arr2[0]);
    }
};

    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), less_than_key()); // n lg n
        
        if (intervals.size() < 2) return true;
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) return false;
        }
        return true;
    }
};
//most voted method
public boolean canAttendMeetings(Interval[] intervals) {
  if (intervals == null)
    return false;

  // Sort the intervals by start time
  Arrays.sort(intervals, new Comparator<Interval>() {
    public int compare(Interval a, Interval b) { return a.start - b.start; }
  });
  
  for (int i = 1; i < intervals.length; i++)
    if (intervals[i].start < intervals[i - 1].end)
      return false;
  
  return true;
}
