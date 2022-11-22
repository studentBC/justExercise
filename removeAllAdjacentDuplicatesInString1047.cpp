class Solution {
public:
    string removeDuplicates(string s) {
        vector<char>ss;
        for (char c : s) {
            if (!ss.empty() && ss.back() == c) ss.pop_back();
            else ss.push_back(c);
        }
        string ans(ss.begin(), ss.end());
        return ans;
    }
};
