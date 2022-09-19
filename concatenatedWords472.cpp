class Solution {
public:
    bool static compare (string& a, string& b) {
        return a.size() < b.size();
    }
    int check (int start, string& target, unordered_set<string>& candidate, vector<int>& dp, int len) {
        if (start >= target.size()) return 1;
        if (dp[start] > -1) return dp[start];
        for (int j = 1; j <= len-start; j++) {
            if (candidate.count(target.substr(start, j)) 
            && check(start+j, target, candidate, dp, len)) return dp[start] = 1;
        }
        return dp[start] = 0;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;
        unordered_set<string> candidate;
        sort(words.begin(), words.end(), compare);
        for (string& s : words) {
            vector<int>dp(s.size(), -1);
            if (check(0, s, candidate, dp, s.size())) ans.push_back(s);
            candidate.insert(s);
        }
        return ans;
    }
};
