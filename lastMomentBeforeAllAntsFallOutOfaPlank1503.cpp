/*
Intuition
When two ants meet at some point,
they change their directions and continue moving again.
But you can assume they don't change direction and keep moving.

(You don't really know the difference of ants between one and the other, do you?)


Explanation
For ants in direction of left, the leaving time is left[i]
For ants in direction of right, the leaving time is n - right[i]


Complexity
Time O(N)
Space O(1)
*/
class Solution {
public:
   int getLastMoment(int n, vector<int>& left, vector<int>& right) {
       int lm = -1, rs = n;
        for (int i: left) {
            lm = max (i, lm);
        }
        for (int i: right) {
            rs = min (i, rs);
        }  
        return max (lm, n-rs);
    }
};
