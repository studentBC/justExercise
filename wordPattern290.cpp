class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string>map;
        string temp = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i]!=' ') {
                temp+=str[i];
            } else {
                map.push_back(temp);
                temp = "";
            }
        }
        map.push_back(temp);
        if (map.size()!=pattern.size())return false;
        string corresponse[26];
        for (int i = 0; i < 26; i++) {
            corresponse[i] = "$";
        }
        for (int i = 0; i < pattern.size(); i++) {
            //cout << corresponse[pattern[i]-'a'] << " , " << map[i] << endl;
            if (corresponse[pattern[i]-'a'].compare("$") == 0) {
                for (int j = 0; j < 26; j++) {
                    if (map[i].compare(corresponse[j]) == 0) {
                        return false;
                    }
                }
                corresponse[pattern[i]-'a'] = map[i];
            } else {
                if (corresponse[pattern[i]-'a'].compare(map[i])!=0) {
                    
                    return false;
                }
            }
        }
        return true;
    }
};
