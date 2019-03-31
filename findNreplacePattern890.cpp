class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        map<char,char>match;
        map<char,char>other;
        bool same;
        auto it = match.begin();
        auto oit = other.begin();
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() == pattern.size()) {
                match.clear();
                other.clear();
                //cout << words[i] << endl;
                same = true;
                for (int j = 0; j < pattern.size(); j++) {
                    it = match.find(pattern[j]);
                    oit = other.find(words[i][j]);
                    if (it == match.end() && oit == other.end()) {
                        match.insert (pair<char,char>(pattern[j],words[i][j]));
                        other.insert (pair<char,char>(words[i][j],pattern[j]));
                    } else {
                        if (it->second != words[i][j] || (oit != other.end() && it == match.end() )) {
                            same = false;
                            break;
                        }
                    }
                }
                if(same)ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string patt = trans(pattern);
        vector<string> res;
        for (auto s : words) {
            if (trans(s) == patt) {
                res.push_back(s);
            }
        }
        return res;
    }
    
    string trans(string pattern) {
        string s;
        unordered_map<char, int> map;
        int tmp = 0;
        for (int i = 0; i < pattern.size(); i++) {
            if (map.count(pattern[i]) == 0) {
                map[pattern[i]] = i;
                s.push_back('a' + tmp++);
            } else {
                s.push_back(s[map[pattern[i]]]);
            }
        }
        return s;
    }
};
