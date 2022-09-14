//Kadanes algorithm
class Solution {
public:
    int largestVariance(string s) {
        int ans = 0, ca, cb, count;
        int freq[26] = {0};
        for (char c : s) freq[c-'a']++;
        unordered_set<char>alpha(begin(s), end(s));
        for (char a : alpha) {
            for (char b: alpha) {
                ca = cb = 0;
                count = freq[a-'a'];
                for (char c : s) {
                    if (c == b) cb++;
                    if (c == a) {
                        ca++;
                        count--;
                    }
                    if (ca) ans = max(ans, cb-ca);
                    if (cb < ca && count > 0) cb = ca = 0;
                }
            }
        }
        return ans;
    }
};
