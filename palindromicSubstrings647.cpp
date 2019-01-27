class Solution {
public:
    bool palindromic (int start, int end, string s) {
        int half = (end-start+1)>>1;
        for (int i = 0; i < half; i++) {
            if (s[start+i] != s[end-i]) {
                return false;
            }
        }
        return true;
    }
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (palindromic(i,j,s)) {
                    count++;
                }
            }
        }
        return count;
    }
};
//the fatest method
class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        for(int i=0;i<s.size();++i){
            for(int j=0;i-j>=0&&i+j<s.size();++j){
                if(s[i-j]==s[i+j])++res;
                else break;
            }
            for(int j=0;i-1-j>=0&&i+j<s.size();++j){
                if(s[i-1-j]==s[i+j])++res;
                else break;
            }
        }
        return res;
    }
};
