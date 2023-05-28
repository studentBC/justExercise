class Solution {
public:
    long long minimumCost(string s) {
        long long ans = 0;
        int len = s.size();
        for (int i = 1; i < len; i++) {
            if (s[i] != s[i-1]) ans +=min(i, len-i);
        }
        return ans;
    }
};
