class Solution {
public:
    string reorganizeString(string S) {
        char prev = '$';
        map<char,int>dict;
        auto it = dict.begin();
        for (int i = 0; i < S.size(); i++) {
            it = dict.find(S[i]); 
            if (it == dict.end()) {
                dict.insert(pair<char,int>(S[i],1));
            } else {
                it->second++;
            }
        }
        string ans = "";
        int max = 0;
        while (ans.size() != S.size()) {
            max = 0;
            for (auto itr = dict.begin(); itr!= dict.end(); itr++) {
                if (max < itr->second && itr->first != prev) {
                    max = itr->second;
                    it = itr;
                }
            }
            if (max > 0) {
                ans+=it->first;
                prev = it->first;
                it->second--;
            } else {
                break;
            }
        }
        if (ans.size()!=S.size()) return "";
        return ans;
    }
};

