class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans = "";
        vector<char>parentheses;
        vector<bool>valid;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                if (parentheses.empty()) {
                    valid.push_back(false);
                    S[i] = '$';
                } else {
                    valid.push_back(true);
                }
                parentheses.push_back(S[i]);
            } else {
                if ( !valid.back() ) {
                    S[i] = '$';
                }
                valid.pop_back();
                parentheses.pop_back();
            }
        }
        for (int i = 0; i < S.size(); i++) {
            if (S[i]!='$') ans+=S[i];
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int cnt = 0, start = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') ++cnt;
            else if (--cnt == 0) {
                ans += S.substr(start + 1, i - start - 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
