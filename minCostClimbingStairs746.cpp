class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int c[cost.size()] = {0};
        for (int i = 2; i < cost.size(); i++) {
            c[i] = min(c[i-2]+cost[i-2] , c[i-1]+cost[i-1]);
        }
        int last = c[cost.size()-1]+cost[cost.size()-1];
        int lasttwo = c[cost.size()-2]+cost[cost.size()-2];
        if (last < lasttwo) {
            return last;
        } else {
            return lasttwo;
        }
    }
};
//fatest method
class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int f1 = 0, f2 = 0;
        for (int k = cost.size() - 1; k >= 0; --k) {
            int f0 = cost[k] + min(f1, f2);
            f2 = f1;
            f1 = f0;
        }
        
        return min(f1, f2);
        
    }
};
