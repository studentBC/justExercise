class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //if (s.size() %2 == 1) return false;
        if (s.size() == 2) {
            return s[0] == s[1];
        }
        string temp = "";
        bool match; 
        int total = s.size() >> 1 , count; 
        for (int i = 1; i <= total; i++) {
            temp = ""; 
            for (int j = 0; j < i; j++) temp+=s[j];
            match = true;
            count = 0; 
            for (int k = i; k < s.size(); k++) {
                if (s[k] != temp[count%i]) {
                    match = false;
                    break;
                }
                count++;
            }
            if (match && count%i == 0) {
                return true;
            }
        }
        return false;
    }
};
//the fatest method
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).substr(1, 2*(s.size()-1)).find(s) != string::npos;
    }
};

