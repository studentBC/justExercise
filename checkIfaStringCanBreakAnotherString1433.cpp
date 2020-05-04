class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool found = true;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] < s2[i]) {
                found = false;
                break;
            }
        }
        if (found) return found;
        else found = true;
        for (int i = 0; i < s1.size(); i++) {
            if (s2[i] < s1[i]) {
                found = false;
                break;
            }
        }
        return found;
    }
};
//72 ms solution
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.size();
        
        vector<int> ct1(26), ct2(26);
        for(int i = 0; i < n; ++i) {
            ++ct1[s1[i]-'a'];
            ++ct2[s2[i]-'a'];
        }
        
        for(int i = 0; i < 26; ++i) {
            int minus = min(ct1[i], ct2[i]);
            ct1[i] -= minus;
            ct2[i] -= minus;
        }
        
        string str1 = "", str2 = "";
        for(int i = 0; i < 26; ++i) {
            while(ct1[i]--) {
                str1.push_back('a' + i);
            }
            
            while(ct2[i]--) {
                str2.push_back('a' + i);
            }
        }
        
        int nn = str1.size();
        if(!nn)
            return true;
        
        bool isLarge = str1[0] > str2[0];
        for(int i = 1; i < nn; ++i) {
            bool lar = str1[i] > str2[i];
            if(lar != isLarge)
                return false;
        }
        return true;
    }
};
