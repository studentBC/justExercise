/*
If there are x (x > 0) number of 1s present, you can convert other non-one elements to 1s by converting first the
nearest elements (as GCD(y, 1) = 1) and then eventually spreading across the array. This can be done in at minimum (n - x) operations.
2. What if there are no 1s present in the array. 2 possibilities then might happen.
You might never get 1. If none of adjacent pair have GCD as 1. No need to handle extra edge cases. we will deal with smartly inside code later.
You might get 1. Without any loss of generality, say there is a range [L, R] and the GCD of this entire range is 1. That means, we can convert one of the elements in the range [L, R] to 1 in (R - L) operations. e.g. consider [4, 6, 3]. GCD of entire range is 1. we can convert the first element 4 to 1 in 2 steps. First, convert 6 to GCD(6, 3) = 3 and then convert 4 to GCD(4, 3) = 1.
Now once we convert any element to 1, we can simply convert other elements to 1 in (n - 1) steps. So total number of operations would be = (R - L + n - 1). Answer would be minimum of this value over all possible ranges, where GCD of range is 1.
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        int one = count(nums.begin(), nums.end(), 1);
        if (one) return n-one;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i+1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = min(ans, j-i+(n-1));
                }
            }
        }
        return ans == INT_MAX? -1 : ans;
    }
};
