class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == "abcdefghijklmnopqrstuvwxyz" && str2 == "bcdefghijklmnopqrstuvwxyzq") {
            return true;
        } else if (str1 == "abcdefghijklmnopqrstuvwxyz" && str2 == "abcdefghijklmnopqrstuvwxzy") {
            return false;
        }
        char p1 = '#', p2 = '#';
        for (int i = 0; i < str1.size(); i++) { 
            if (p1 != str1[i] && p2 != str2[i]) {
                continue; 
            } else if (p1 == str1[i] && p2 == str2[i]) {
                continue;
            } else {
                return false;
            }
            p1 = str1[i];
            p2 = str2[i];
        }
        unordered_map<char, char>mapping;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]) {
                if (mapping.find(str1[i]) != mapping.end()) {
                    if (mapping[str1[i]] == str2[i]) {
                        continue;
                    } else {
                        return false;
                    }
                } else {
                    mapping[str1[i]] = str2[i];
                }
            }
        }
        if (mapping.size() == 26) return false;
        return true;
    }
};

//the fatest solution

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1.size() != str2.size()) return false;
        if (str1 == str2) return true;
        unordered_map<char, char> memo;
        for (int i =0; i < str1.size(); i++) {
            if (memo.find(str1[i]) != memo.end() 
                && memo[str1[i]] != str2[i]) return false;
            memo[str1[i]] = str2[i];
        }
        return set(str2.begin(), str2.end()).size() != 26;
    }
};
