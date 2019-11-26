class Solution {
public:
    string toGoatLatin(string S) {
        istringstream ss(S);
        string s, ans;
        int count = 1;
        while (ss >> s) {
            if (tolower(s[0]) == 'a' || tolower(s[0]) == 'e' || tolower(s[0]) == 'i' || tolower(s[0]) == 'o' || tolower(s[0]) == 'u') {
                s+="ma";
            } else {
                s.push_back (s[0]);
                s.erase(0,1);
                s+="ma";
            }
            for (int i = 0; i < count; i++) {
                s.push_back('a');
            }
            count++;
            s.push_back(' ');
            ans+=s;
        }
        ans.pop_back();
        return ans;
    }
};

