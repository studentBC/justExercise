class Solution {
public:
    int countSubstrings(string s, string t) {
        int slen = s.size(), tlen = t.size(), count = 0, ans = 0;
        for (int i = 0; i < slen; i++) {
            for (int j = 0; j < tlen; j++) {
                count = 0;
                for (int k = 0; k+i < slen && k+j < tlen; k++) {
                    if (s[k+i]!=t[k+j] && ++count > 1) {
                        break;
                    }
                    ans+=count;
                }
            }
        }
        return ans;
    }
};
