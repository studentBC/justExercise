class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        vector<vector<string>>word;
        unordered_set<string>unique;
        for (string s:phrases) {
            istringstream ss (s);
            string temp;
            vector<string>tmp;
            while ( getline(ss, temp, ' ' ) ) {
                tmp.emplace_back( temp.c_str() );
            }
            word.emplace_back(tmp);
        }
        for (int i = 0; i < word.size(); i++) {
            for (int j = 0; j < word.size(); j++) {
                if (i!=j && word[i].back() == word[j].front()) {
                    string s = phrases[i];
                    for (int k = 1; k < word[j].size(); k++) {
                        s+=" ";
                        s+=word[j][k];
                    }
                    //cout << s << endl;
                    unique.insert(s);
                }  
            }
        }  
        vector<string>ans(unique.begin(), unique.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
//the fatest solution
static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string, vector<int>> m;
        int i, n = phrases.size(), len;
        size_t j;
        for (i = 0; i < n; ++i) {
            j = phrases[i].find_first_of(' ');
            if (j == string::npos) m[phrases[i]].push_back(i);
            else m[phrases[i].substr(0, j)].push_back(i);
        }
        
        set<string> s;        
        for (i = 0; i < n; ++i) {
            j = phrases[i].find_last_of(' ');
            string key = (j == string::npos) ? phrases[i] : phrases[i].substr(j + 1);
            unordered_map<string, vector<int>>::iterator it = m.find(key);
            if (it == m.end()) continue;
            len = key.size();
            for (int t : it->second)
                if (t != i) s.emplace(phrases[i] + phrases[t].substr(len));
        }
        
        return vector<string>(s.begin(), s.end());
    }
};
