/*
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2

Example 2:

Input: [[7,10],[2,4]]
Output: 1
[[9,10],[4,9],[4,17]] 2
[[5,8],[6,8]] 2
[[13,15],[1,13]] 1
[[6,15],[13,20],[6,17]] 
 */
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        int ans = 1;
        vector<int>count(1000000,0);
        for (int i = 0; i < intervals.size(); ++i) {
            for (int j = intervals[i][0]; j < intervals[i][1]; ++j) {
                count[j]++;
                ans = max(count[j], ans);
            }
        }
        return ans;
    }
};
//8 ms solution
#include <vector>
#include <algorithm>

using namespace std;

static const auto apparently_we_do_this_now = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		vector<pair<int, int>> sorted;
		sorted.reserve(intervals.size());
		for (auto& it : intervals)
			sorted.push_back(std::make_pair(it[0], it[1]));
		sort(sorted.begin(), sorted.end());
        
        vector<int> reservations;
        for (const auto& it : sorted)
        {
            bool bReserved = false;
            for (int i = 0; i < reservations.size(); ++i)
            {
                if (reservations[i] <= it.first)
                {
                    reservations[i] = it.second;
                    bReserved = true;
                    break;
                }
            }
            
            if (!bReserved)
            {
                reservations.push_back(it.second);
            }
        }
        return reservations.size();
	}
};
/*
 *
Intuition

This problem is very similar to something that employees of a company can face potentially on daily basis.

Suppose you work at a company and you belong to the IT department and one of your job responsibilities is securing rooms for meetings that are to happen throughout the day in the office.

You have multiple meeting rooms in the office and you want to make judicious use of them. You don't really want to keep people waiting and want to give a group of employees a room to hold the meeting right on time.

At the same time, you don't really want to use too many rooms unless absolutely necessary. It would make sense to hold meetings in different rooms provided that the meetings are colliding with each other, otherwise you want to make use of as less rooms as possible to hold all of the meetings. How do you go about it ?

I just represented a common scenario at an office where given the start and end times for meetings to happen throughout the day, you, as an IT guy need to setup and allocate the room numbers to different teams.

Let's approach this problem from the perspective of a group of people who want to hold a meeting and have not been allocated a room yet. What would they do?

    This group would essentially go from one room to another and check if any meeting room is free. If they find a room that is indeed free, they would start their meeting in that room. Otherwise, they would wait for a room to be free. As soon as the room frees up, they would occupy it.

This is the basic approach that we will follow in this question. So, it is a kind of simulation but not exactly. In the worst case we can assign a new room to all of the meetings but that is not really optimal right? Unless of course they all collide with each other.

    We need to be able to find out efficiently if a room is available or not for the current meeting and assign a new room only if none of the assigned rooms is currently free.

Let's look at the first approach based on the idea we just discussed.
Approach 1: Priority Queues

We can't really process the given meetings in any random order. The most basic way of processing the meetings is in increasing order of their start times and this is the order we will follow. After all if you're an IT guy, you should allocate a room to the meeting that is scheduled for 9 a.m. in the morning before you worry about the 5 p.m. meeting, right?

Let's do a dry run of an example problem with sample meeting times and see what our algorithm should be able to do efficiently.

We will consider the following meeting times for our example (1, 10), (2, 7), (3, 19), (8, 12), (10, 20), (11, 30). The first part of the tuple is the start time for the meeting and the second value represents the ending time. We are considering the meetings in a sorted order of their start times. The first diagram depicts the first three meetings where each of them requires a new room because of collisions.

The next 3 meetings start to occupy some of the existing rooms. However, the last one requires a new room altogether and overall we have to use 4 different rooms to accommodate all the meetings.

Sorting part is easy, but for every meeting how do we find out efficiently if a room is available or not? At any point in time we have multiple rooms that can be occupied and we don't really care which room is free as long as we find one when required for a new meeting.

A naive way to check if a room is available or not is to iterate on all the rooms and see if one is available when we have a new meeting at hand.

    However, we can do better than this by making use of Priority Queues or the Min-Heap data structure.

Instead of manually iterating on every room that's been allocated and checking if the room is available or not, we can keep all the rooms in a min heap where the key for the min heap would be the ending time of meeting.

So, every time we want to check if any room is free or not, simply check the topmost element of the min heap as that would be the room that would get free the earliest out of all the other rooms currently occupied.

If the room we extracted from the top of the min heap isn't free, then no other room is. So, we can save time here and simply allocate a new room.

Let us look at the algorithm before moving onto the implementation.

Algorithm

    Sort the given meetings by their start time.
    Initialize a new min-heap and add the first meeting's ending time to the heap. We simply need to keep track of the ending times as that tells us when a meeting room will get free.
    For every meeting room check if the minimum element of the heap i.e. the room at the top of the heap is free or not.
    If the room is free, then we extract the topmost element and add it back with the ending time of the current meeting we are processing.
    If not, then we allocate a new room and add it to the heap.
    After processing all the meetings, the size of the heap will tell us the number of rooms allocated. This will be the minimum number of rooms needed to accommodate all the meetings.

Let us not look at the implementation for this algorithm.
 */
