class Solution {
public:
    int minAddToMakeValid(string S) {
        vector<char>parenthese;
        for (char c:S) {
            if (c == '(') {
                parenthese.emplace_back(c);
            } else {
                if (!parenthese.empty() && parenthese.back() == '(') {
                    parenthese.pop_back();
                } else {
                    parenthese.emplace_back(c);
                }
            }
        }
        return parenthese.size();
    }
};
//the fatest method
class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0;
        int cnt = 0;
        for (const auto& c : S) {
            if (c == '(')
                ++left;
            else
                --left;
            if (left < 0) {
                cnt -= left;
                left = 0;
            }
        }
        return cnt + left;
    }
};
