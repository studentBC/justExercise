class Solution {
public:
    bool check (int alpha[], int target[]) {
        for (int i = 0; i < 26; i++) {
            if (alpha[i]!=target[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int target[26] = {0};
        int end = s2.size()-s1.size(), len = s1.size()-1;
        int alpha[26] = {0};
        for (char c:s1) target[c-'a']++;
        for (int i = 0; i < s1.size(); i++) {
            alpha[s2[i]-'a']++;
        }
        if (check(alpha, target)) return true;
        for (int i = 1; i <= end; i++) {
            alpha[s2[i-1]-'a']--;
            alpha[s2[i+len]-'a']++;
            if (check(alpha, target)) return true;
        }
        return false;
    }
};
//the fatest soution

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size()<s1.size()) return false;
        
        vector<int> cnt1(26,0);
        vector<int> cnt2(26,0);
        
        for (char ch:s1) cnt1[ch-'a']++;
        for (int i=0; i<s1.size(); i++) {
            cnt2[s2[i]-'a']++;
        }
        if (cnt1==cnt2) return true;
        
        for (int i=0; i<s2.size()-s1.size(); i++) {
            cnt2[s2[i]-'a']--;
            cnt2[s2[i+s1.size()]-'a']++;
            if (cnt1==cnt2) return true;
        }
        return false;
    }
};
