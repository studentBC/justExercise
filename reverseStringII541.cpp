class Solution {
public:
    string reverseStr(string s, int k) {
        int len = k <<1, length;
        if (k >= s.size()) {
            reverse(s.begin(), s.end());
            return s;
        }
        for (int i = 0; i < s.size(); i+=len) {
            length = i+k;
            if (length > s.size()) {
                reverse(s.begin()+i, s.end());
            } else {
                reverse(s.begin()+i, s.begin()+length);
            }
        }
        return s;
    }
};
//the fatest method
class Solution {
public:
    string reverseStr(string s, int k) {
        int i, j, ii;
        string temp;
        ii = 0;
        bool rev = true;
        for (i = 0; i < s.length(); i += k){
            if (rev){
               if (i + k > s.length())
                    temp = s.substr(i, s.length() - i);
                else

                    temp = s.substr(i, k);

                for (j = temp.length() - 1; j >= 0 ; j--){
                    s[ii] = temp[j];
                    ii++;
                } 
                rev = false;
            }else{
                ii += k;
                rev = true;
            }
            
            
        }
        return s;
    }
};
