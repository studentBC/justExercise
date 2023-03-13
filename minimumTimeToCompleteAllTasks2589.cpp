/*
We first sort tasks by the end time.

For the task with the closest end time, the best strategy is to finish it as late as possible.

That way, we have the best chance for the computer time to be reused by tasks that end later.

We use line to mark the computer "on" slots. When we process a task, we count "on" slots within the interval.

We can use BIT to get the number of "on" slots for an interval - see the solutoin below.

If we still need additional time to finish the task, we pick available slots starting from the end time (as late as possible).
*/
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int line[2001] = {};
        sort(tasks.begin(), tasks.end(), [](const auto &t1, const auto &t2) {
            return t1[1] < t2[1];
        });
        for (auto& t : tasks) {
            int start = t[0], end = t[1], d = t[2];
            d-=count(begin(line) + start, begin(line)+end+1, true);
            for (int i = end; d > 0; i--) {
                d-=!line[i];
                line[i] = true;
            }
        }
        return count(begin(line), end(line), true);
    }
};
