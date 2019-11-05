class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char>valid;
        stack<int>pos;
        vector<bool>contain(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                if (!valid.empty() && valid.top() == '(') {
                    contain[pos.top()] = true;
                    contain[i] = true;
                    valid.pop();
                    pos.pop();
                }
            } else if (s[i] == '(') {
                valid.push(s[i]);
                pos.push(i);
            } else {
                contain[i] = true;
            }
        }
        string ans;
        for (int i = 0; i < contain.size(); i++) {
            if (contain[i]) ans+=s[i];
        }
        return ans;
    }
};
//the fatest solution
static int x=[](){std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}(); // NOLINT

class Solution1 {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            }
            if (s[i] == ')') {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    s[i] = '*';
                }
            }
        }

        while (!stk.empty()) {
            s[stk.top()] = '*';
            stk.pop();
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());

        return s;
    }
};

using Solution = Solution1;

