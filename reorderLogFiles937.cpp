//2022 9 14 beat 93%
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<int> digit;
        vector<pair<string, int>>letter;
        int i = 0;
        for (string& s: logs) {
            istringstream iss(s);
            string last, tmp, ss;
            iss>>last;
            iss>>tmp;
            if (isdigit(tmp[0])) {
                digit.push_back(i);
            } else {
                ss = tmp+" ";
                while (iss>>tmp) {
                    ss+=tmp;
                    ss+=" ";
                }
                ss+=" ";
                ss+=last;
                //cout << ss << endl;
                letter.push_back({ss, i});
            }
            i++;
        }
        sort(letter.begin(), letter.end());
        vector<string>ans;
        for (int i = 0; i < letter.size(); i++) {
            ans.push_back(logs[letter[i].second]);
        }
        for (int i : digit) {
            ans.push_back(logs[i]);
        }
        return ans;
    }
};

class Solution {
public:
    static bool compare (tuple<string, string, int>& a, tuple<string, string, int>& b) {
        if (get<0>(a) == get<0>(b)) {
            return get<1>(a) < get<1>(b);
        } else {
            return get<0>(a) < get<0>(b);
        }
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        string temp, key, value;
        vector<tuple<string, string, int>>letterlogs;
        for (int i = 0; i < logs.size(); i++) {
            istringstream ss (logs[i]);
            ss >> key; ss>>temp;
            //cout << temp <<" , " << key << endl;
            if (temp.size() && isalpha(temp[0])) {
                value = temp;
                while (ss >> temp) {
                    value+=" ";
                    value+=temp;
                }
                //cout << value <<" , " << key << endl;
                letterlogs.emplace_back(make_tuple(value,key,i));
            }
        }
        sort(letterlogs.begin(), letterlogs.end(), compare);
        vector<string>ans;
        for (int i = 0; i < letterlogs.size(); i++) {
            ans.emplace_back(logs[get<2>(letterlogs[i])]);
            logs[get<2>(letterlogs[i])] = "$";
        }
        for (string s:logs) {
            if (s!="$") ans.emplace_back(s);
        }
        return ans;
    }
};
//the fatest method
#include <bits/stdc++.h>

using namespace std;

struct letter_log {
    const string *line;
    size_t body_start;

    letter_log(const string *line, size_t body_start) :
        line(line), body_start(body_start) {}

    char body_at(size_t idx) const {
        return (*line)[body_start + idx];
    }

    size_t body_size() const {
        return (*line).size() - body_start;
    }
};

bool operator<(const letter_log &lhs, const letter_log &rhs) {
    size_t idx = 0;
    while (idx < lhs.body_size() && idx < rhs.body_size()) {
        if (lhs.body_at(idx) != rhs.body_at(idx)) {
            return lhs.body_at(idx) < rhs.body_at(idx);
        }
        ++idx;
    }
    if (lhs.body_size() != rhs.body_size()) {
        return lhs.body_size() < rhs.body_size();
    }

    idx = 0;
    while (idx < lhs.body_start && idx < rhs.body_start) {
        if (lhs.line[idx] != rhs.line[idx]) {
            return lhs.line[idx] < rhs.line[idx];
        }
        ++idx;
    }
    if (lhs.body_start != rhs.body_start) {
        return lhs.body_start < rhs.body_start;
    }
    return false;
}

struct digit_log {
    const string *line;

    digit_log(const string *line) : line(line) {}
};

class Solution {
    static bool is_letter(char ch) {
        return 'a' <= ch && ch <= 'z';
    }

    static bool is_digit(char ch) {
        return '0' <= ch && ch <= '9';
    }

public:
    vector<string> reorderLogFiles(const vector<string> &logs) {
        vector<letter_log> letter_logs;
        vector<digit_log> digit_logs;

        for (const auto &log : logs) {
            auto space_it = find_if(log.begin(), log.end(), [](char ch) { return ch == ' '; });
            size_t body_start = space_it - log.begin() + 1;

            if (is_letter(log[body_start])) {
                letter_logs.emplace_back(&log, body_start);
            } else {
                assert(is_digit(log[body_start]));
                digit_logs.emplace_back(&log);
            }
        }

        sort(letter_logs.begin(), letter_logs.end());

        vector<string> result(digit_logs.size() + letter_logs.size());
        transform(letter_logs.begin(), letter_logs.end(), result.begin(),
                  [](letter_log l) -> string { return *l.line; });
        transform(digit_logs.begin(), digit_logs.end(), result.begin() + letter_logs.size(),
                  [](digit_log l) -> string { return *l.line; });
        return result;
    }
};

#ifdef DEBUG

int main() {
    Solution s;
    s.reorderLogFiles({"a1 9 2 3 1", "zo4 4 7"});
//    s.reorderLogFiles({"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"});
//    assert(letter_log("a81 act car", 4) < letter_log("g1 act zoo", 3));
//    assert(letter_log("a81 act", 4) < letter_log("g1 act zoo", 3));
//    assert(letter_log("a81 act ", 4) < letter_log("g1 act zoo", 3));
//    assert(letter_log("g01 act zoo", 4) < letter_log("g1 act zoo", 3));
//    assert(!(letter_log("g1 act zoo", 3) < letter_log("g1 act zoo", 3)));
}

#endif
