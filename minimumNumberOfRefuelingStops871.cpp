/*
 * We notice that apparently the max distance does not depends on the station's position, but the station's fuel.
Apparently, the maximum distance of k+1 steps = maximum distance of k steps + maximum fuel of stations that the car has passed by (counting from the last station that makes the previous maximum distance)
 */
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;
        priority_queue<int>pq;
        int dist = startFuel, i = 0, ans = 0;
        while (dist < target) {
            while (i < stations.size() && stations[i][0] <= dist) {
                pq.push(stations[i++][1]);
            }
            if (pq.empty()) return -1;
            dist += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};
