/*
 Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration, return the earliest time slot that works for both of them and is of duration duration.

If there is no common time slot that satisfies the requirements, return an empty array.

The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.

 

Example 1:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
Output: [60,68]
Example 2:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
Output: []
 

Constraints:

1 <= slots1.length, slots2.length <= 104
slots1[i].length, slots2[i].length == 2
slots1[i][0] < slots1[i][1]
slots2[i][0] < slots2[i][1]
0 <= slots1[i][j], slots2[i][j] <= 109
1 <= duration <= 106
 */
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        map<int,int>count;
        for (int i = slots1.size()-1; i > -1; i--) {
            count[slots1[i][0]]++;
            count[slots1[i][1]+1]--;
        }
        for (int i = slots2.size()-1; i > -1; i--) {
            count[slots2[i][0]]++;
            count[slots2[i][1]+1]--;
        }
        int sum = 0, val = 0, start = -1, prev = 1e9+7;
        for (auto& it: count) {
            sum+=it.second;
            //cout << it.first <<" : " << sum << endl;
            if (sum == 2) {
                if (it.first - prev >= duration) return {prev, it.first};
                prev = it.first;
            } else {
                if (it.first- 1 - prev >= duration) return {prev, prev+duration};
                prev = INT_MAX;
            }
            
        }
        return {};
    }
};
//104 ms solution
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        std::map<int, int> meetingSchedMap;
        for(auto& next : slots1)
        {
            if(next[1] - next[0] >= duration)
            {
                meetingSchedMap[next[0]] += 1;
                meetingSchedMap[next[1]] -= 1;
            }
        }
        for(auto& next : slots2)
        {
            if(next[1] - next[0] >= duration)
            {
                meetingSchedMap[next[0]] += 1;
                meetingSchedMap[next[1]] -= 1;
            }
        }
        int slotsAvailable = 0;
        int bothSlotsAvailableAt = -1;
        for(auto& next  :   meetingSchedMap)
        {
            slotsAvailable += next.second;
            if(slotsAvailable == 2)
            {
                bothSlotsAvailableAt = next.first;
            }
            else
            {
                if(bothSlotsAvailableAt != -1)
                {
                    if(next.first - bothSlotsAvailableAt >= duration)
                    {
                        return std::vector<int>{bothSlotsAvailableAt, bothSlotsAvailableAt+duration};
                    }
                    bothSlotsAvailableAt = -1;
                }
            }
        }
        return std::vector<int>{};
    }
};
