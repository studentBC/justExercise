//https://www.youtube.com/watch?v=DbfHIdZL8rQ&ab_channel=CodeWithSunny
class Solution {
public:
    int largestVariance(string s) {
        int ans = 0, ca, cb, count;
        int freq[26] = {0};
        for (char c : s) freq[c-'a']++;
        unordered_set<char>alpha(begin(s), end(s));
        for (char a : alpha) {
            for (char b: alpha) {
                if (a == b) continue;
                //count = freq[a-'a'];
                for (int i = 0; i < 2; i++) {
                    
                    ca = cb = 0;
                    for (char c : s) {
                        if (c == b) cb++;
                        if (c == a) {
                            ca++;
                        }
                        //cout << cb <<", " << ca << endl;
                        if (cb < ca) cb = ca = 0;
                        if (ca && cb && cb > ca) ans = max(ans, cb-ca);
                    }
                    reverse(s.begin(), s.end());
					//we do the reverse for the corner cases like
					//abbbbb
                }
                
            }
        }
        return ans;
    }
};
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
