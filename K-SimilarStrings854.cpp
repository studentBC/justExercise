//good BFS problem, we only need to exchange the valid or efficient character between two character
class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        unordered_set<string>used;
        queue<string>q;
        q.push(s1);
        int ans = 0;
        string s;
        while (!q.empty()) {
            ans++;
            for (int i = (int)q.size(), j = 0; i > 0; i--) {
                s = q.front();
                q.pop();
                used.insert(s);
                j = 0;
                while (s[j] == s2[j]) j++;
                for (int k = j+1; k < s.size(); k++) {
                    if (s[k] == s2[k] || s[k]!=s2[j]) continue;
                    string tmp = s;
                    swap(tmp[j], tmp[k]);
                    if (tmp == s2) return ans; 
                    if (!used.count(tmp)) q.push(tmp);
                }
            }
        }
        return ans;
    }
};
