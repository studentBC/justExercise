class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int b = buses.size(), p = passengers.size();
        int ans = 0, late;
        for (int i = 0, j = 0; i < b; i++) {
            int count = 0;
            while (j < p && passengers[j] <= buses[i] && count < capacity) {
                j++;
                count++;
            }
            if (i == b-1) {
                if (count < capacity) {
                    late = buses[i];
                    for (int k = j-1; k > -1 && passengers[k] == late; k--, late--);
                    ans = max(ans, late);
                } else {
                    late = passengers[j-1]-1;
                    for (int k = j-2; k > -1 && passengers[k] == late; k--, late--);
                    ans = max(ans, late);
                }
            } 
        }
        return ans;
    }
};
//my python solution
class Solution:
    def latestTimeCatchTheBus(self, buses: List[int], passengers: List[int], capacity: int) -> int:
        heapq.heapify(buses)
        heapq.heapify(passengers)
        uniq = set(passengers)
        for i in range(len(buses)):
            depart = heapq.heappop(buses)
            if len(buses) == 0:
                c = capacity
                for i in range(capacity):
                    if len(passengers) == 0:
                        break
                    if passengers[0] <= depart:
                        last = heapq.heappop(passengers)
                        c-=1
                    else:
                        break
                #print("we left", c)
                if c == 0:
                    for i in range(last-1, -1, -1):
                        if i not in uniq:
                            return i
                else:
                    #print("enter here")
                    for i in range(depart, -1, -1):
                        if i not in uniq:
                            return i
            else:
                for i in range(capacity):
                    if len(passengers) == 0:
                        break
                    if passengers[0] <= depart:
                        heapq.heappop(passengers)
        return 0
