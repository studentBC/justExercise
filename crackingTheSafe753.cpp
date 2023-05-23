class Solution {
public:
    int total, n, k;
    bool go (string& ans, unordered_set<string>& used) {
        if (used.size() == total) return true;
        for (int i = 0; i < k; i++) {
            ans.push_back('0'+i);
            string cur = ans.substr(ans.size()-n);
            if (!used.count(cur)) {
                used.insert(cur);
                if (go(ans, used)) return true;
                used.erase(cur);
            }
            ans.pop_back();
        }
        return false;
    }
    string crackSafe(int n, int k) {
        this-> n = n;
        this->k = k;
        total = pow(k, n);
        string ans(n, '0');
        unordered_set<string>used = {ans};
        go (ans, used);
        return ans;
    }
};
