class Solution {
public:
    long long numberOfWays(string s) {
        long long one = 0, zero = 0, ans = 0, co = 0, cz = 0;
        for (char c : s) {
            if (c == '1') one++;
            else zero++;
        }
        for (char c : s) {
            if (c == '1') {
                ans+=cz*zero;
                one--;
                co++;
            } else {
                ans+=co*one;
                cz++;
                zero--;
            }
        }
        return ans;
    }
};
