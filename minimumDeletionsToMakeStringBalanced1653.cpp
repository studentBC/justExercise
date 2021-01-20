class Solution {
public:
    int minimumDeletions(string s) {
        vector<int>ca(s.size(), 0), cb(s.size(), 0);
        int n = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'b') n++;
            cb[i] = n;
        }
        n = 0;
        for (int i = s.size()-1; i > -1; i--) {
            if (s[i] == 'a') n++;
            ca[i] = n;
        }
        int ans = s.size();

        for (int i = 0; i < s.size(); i++) {
            n = ca[i] + cb[i];
            ans = min(ans, n);
        }
        return ans-1;
    }
};
