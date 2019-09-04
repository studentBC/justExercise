class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        vector<int**>alpha;
        for (int i = 0; i < A.size(); i++) {
            int** temp = new int* [2];
            temp[0] = new int [26];temp[1] = new int [26];
            for (int j = 0; j < A[i].size(); j+=2) {
                temp[0][A[i][j]-'a']++;
            }
            for (int j = 1; j < A[i].size(); j+=2) {
                temp[1][A[i][j]-'a']++;
            }
            alpha.emplace_back(temp);
        }
        vector<bool>used(alpha.size(), false);
        int count = 0;
        bool found;
        for (int i = 0; i < alpha.size(); i++) {
            if (!used[i]) {
                for (int j = 0; j < alpha.size(); j++) {
                    if (!used[j]) {
                        found = false;
                        for (int k = 0; k < 26; k++) {
                            if (alpha[i][0][k] != alpha[j][0][k] || alpha[i][1][k] != alpha[j][1][k]) {
                                found = true;break;
                            }
                        }
                        if(!found) {
                            used[i] = used[j] = true;
                        }
                    }
                }
                if(used[i])count++;
            }
        }
        return count;
    }
};
//the fatest solution
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> fts;
        for (auto& s : A) {
            string ft(52, '\0');
            for (int i = 0, n = s.size(); i < n; ++i) {
                ++ft[s[i] - 'a' + ((i&1)?26:0)];
            }
            fts.insert(move(ft));
        }
        return fts.size();
    }
};
auto _=[](){ios::sync_with_stdio(0);cin.tie(0);return cout.tie(0);}();
