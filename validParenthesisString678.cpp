class Solution {
public:
bool checkValidString(string s) {
        vector<char>temp;
        int index;
        for (char c:s) {
            if (c != ')') {
                temp.emplace_back(c);
            } else {
                index = -1;
                for (int j = temp.size()-1; j > -1; j--) {
                    if (temp[j] == '(') {
                        temp.erase(temp.begin()+j);
                        index = INT_MAX;
                        break;
                    } else if (temp[j] == '*') {
                        if (index < j) index = j;
                    }
                }
                if (index == -1) {
                    return false;
                } else if (index != INT_MAX) {
                    temp.erase(temp.begin()+index);
                }
            }
        }
        vector<char>tmp;
        for (char c:temp) {
            if (c == '(') {
                tmp.emplace_back('(');
            } else {
                if (tmp.size()) {
                    tmp.pop_back();
                }
            }
        }
        return tmp.size() == 0;
    }
};
//the fatest method
class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '*') ++left;
            else --left;
            if (left < 0) return false;
        }
        if (left == 0) return true;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || s[i] == '*') ++right;
            else --right;
            if (right < 0) return false;
        }
        return true;
    }
};
