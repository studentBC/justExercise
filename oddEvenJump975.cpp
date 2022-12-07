/*
 * We need to jump higher and lower alternately to the end.

Take [5,1,3,4,2] as example.

If we start at 2,
we can jump either higher first or lower first to the end,
because we are already at the end.
higher(2) = true
lower(2) = true

If we start at 4,
we can't jump higher, higher(4) = false
we can jump lower to 2, lower(4) = higher(2) = true

If we start at 3,
we can jump higher to 4, higher(3) = lower(4) = true
we can jump lower to 2, lower(3) = higher(2) = true

If we start at 1,
we can jump higher to 2, higher(1) = lower(2) = true
we can't jump lower, lower(1) = false

If we start at 5,
we can't jump higher, higher(5) = false
we can jump lower to 4, lower(5) = higher(4) = false
 */
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int ans = 1, len = arr.size();
        vector<bool>higher(len, false), lower(len, false);
        map<int, int> num;
        higher.back() = lower.back() = true;
        num[arr[len - 1]] = len - 1;
        for (int i = len-2; i > -1; i--) {
            auto hi = num.lower_bound(arr[i]), lo = num.upper_bound(arr[i]);
            if (hi!=num.end()) higher[i] = lower[hi->second];
            if (lo!=num.begin()) lower[i] = higher[(--lo)->second];
            if (higher[i]) ans++;
            num[arr[i]] = i;
        }
        return ans;
    }
};
