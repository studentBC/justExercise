class Solution {
public:
    string shortestPalindrome(string s) {
        int shortest = INT_MAX, pivot, left, right, diff, len;
        bool one;
        bool canbe = false;
        for (int i = 0; i < s.size(); i++) {
            left = i;
            right = s.size()-i-1;
            diff = min(left, right);
            canbe = true;
            for (int j = 0; j < diff; j++) {
                if (s[i-1-j] != s[i+1+j]) {
                    canbe = false;break;
                }
            }
            if (canbe && left <= right) {
                len = 2*max(left, right)+1;
                if (shortest > len) {
                    shortest = len;
                    one = true;
                    pivot = i;
                }
            }
            if (i+1 < s.size() && s[i] == s[i+1]) {
                left = i;
                right = s.size()-i-2;
                diff = min(left, right);
                canbe = true;
                for (int j = 0; j < diff; j++) {
                    if (s[i-1-j] != s[i+2+j]) {
                        canbe = false;break;
                    }
                }
                if (canbe && left <= right) {
                    len = 2*max(left, right)+2;
                    if (shortest > len) {
                        shortest = len;
                        one = false;
                        pivot = i;
                    }
                }
            }
        }
        string ans;
        //cout <<"choose pivot " << pivot << endl;
        if (one) {
            left = pivot;
            right = s.size()-pivot-1;
            diff = max(left, right);
            ans = s[pivot];
            for (int i = 0; i < diff; i++) {
                if (i+1+pivot < s.size()) {
                    ans+=s[i+1+pivot];
                    ans.insert(0,1,s[i+1+pivot]);
                } else if (pivot-i-1 > -1) {
                    ans+=s[pivot-i-1];
                    ans.insert(0,1,s[pivot-i-1]);
                }
            }
        } else {
            ans = s[pivot];
            ans+=s[pivot+1];
            left = pivot;
            right = s.size()-pivot-1;
            diff = max(left, right);
            for (int i = 0; i < diff; i++) {
                if (i+2+pivot < s.size()) {
                    ans+=s[i+2+pivot];
                    ans.insert(0,1,s[i+2+pivot]);
                } else if (pivot-i-1 > -1) {
                    ans+=s[pivot-i-1];
                    ans.insert(0,1,s[pivot-i-1]);
                }
            }
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    string shortestPalindrome(string s) {
    int n = s.size();
    int i = 0;
    for (int j = n - 1; j >= 0; j--) {
        if (s[i] == s[j])
            i++;
    }
    if (i == n)
        return s;
    string remain_rev = s.substr(i, n);
    reverse(remain_rev.begin(), remain_rev.end());
    return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
        
    }
};
