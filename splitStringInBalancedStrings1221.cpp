class Solution {
public:
    bool check (string temp) {
        int r = 0, l = 0;
        for (char c: temp) {
            if (c == 'R') {
                r++;
            } else {
                l++;
            }
        }
        return r == l;
    }
    void go (int i, int count, string s, int& ans) {
        if (ans) return;
        if (i == s.size()) {
            ans = max (count ,ans);
        } else {
            string temp;
            int c = 0;
            for (int a = i; a < s.size(); a++) {
                temp.push_back(s[a]);
                c++;
                //cout << temp << endl;
                if (check(temp)) {
                    //cout << temp <<" start from " << a+1 << endl;
                    go (a+1, count+1, s, ans);
                    while (c) {
                        temp.pop_back();
                        c--;
                    }
                }
            }
        }
    }
    int balancedStringSplit(string s) {
        int ans = 0;
        go (0, 0, s, ans);
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    int balancedStringSplit(string s) {
        int sum = 0, ans = 0;
        for (char c: s) {
            if (c == 'L') sum++;
            else sum--;
            if (sum == 0) ans++;
        }
        return ans;
    }
};
