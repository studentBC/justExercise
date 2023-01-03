class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>ee;
        for (string& s: emails) {
            string tmp;
            bool start = false, st = false;
            for (char c : s) {
                if (start || c == '@') {
                    tmp.push_back(c);
                    start = true;
                } else {
                    if (st) continue;
                    else if (c == '.') continue;
                    else if (c == '+') st = true;
                    else tmp.push_back(c);
                }
            }
            ee.insert(tmp);
        }
        return ee.size();
    }
};
