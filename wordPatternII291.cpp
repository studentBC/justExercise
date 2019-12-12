/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Example 1:

Input: pattern = "abab", str = "redblueredblue"
Output: true
Example 2:

Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
Output: true
Example 3:

Input: pattern = "aabb", str = "xyzabcxzyabc"
Output: false
Notes:
You may assume both pattern and str contains only lowercase letters.


wrong test case: 
"ab"
"aa"
*/
class Solution {
public:
    void go (int i, int start, string pattern, string str, bool& ans, unordered_map<char, string> match) {
        if (ans) return;
        if (i == pattern.size() || start == str.size() ) {
            if (i == pattern.size() && start == str.size()) {
                bool valid = true;
                unordered_set<string>repeat;
                for (auto& it: match) {
                    if (repeat.count(it.second) ) {
                        valid = false;
                        break;
                    }
                    repeat.insert(it.second);
                }
                if (valid) ans = true;
            }
            return;
        }
		if (match.count(pattern[i])) {
			for (int j = start, k = 0; j < str.size() && k < match[pattern[i]].size(); j++,k++) {
				if (match[pattern[i]][k] != str[j]) return;
			}
			if (start+match[pattern[i]].size() <= str.size()) go (i+1, start+match[pattern[i]].size() , pattern, str, ans, match);
			else return;
		} else {
			string tmp;
			for (int j = start; j < str.size(); j++) {
				tmp+=str[j];
				match[pattern[i]] = tmp;
				go (i+1, j+1, pattern, str, ans, match);
			}
		}
    }
    bool wordPatternMatch(string pattern, string str) {
        bool ans = false;
        unordered_map<char, string>match;
        go (0, 0, pattern, str, ans, match);
        return ans;
    }
};

//the fatest solution
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        vector<string> smap(26, "");
        unordered_set<string> hset;
        return wordPatternMatch(pattern, str, smap, hset, 0, str.length()-1, 0, pattern.length()-1);
    }
    
private:
    bool wordPatternMatch(string& pattern, string& str, vector<string>& smap, unordered_set<string>& hset,
                             int start, int end, int startP, int endP) {
        if (startP == endP+1 && start == end+1) {
            return true;
        }
        if ((startP > endP && start <= end) || startP < endP && start > end) {
            return false;
        }
        
        char ch = pattern[startP];
        string matched = smap[ch-'a'];
        if (!matched.empty()) {
            int count = matched.length();
            return start + count <= end+1 && matched == str.substr(start, count)
                && wordPatternMatch(pattern, str, smap, hset, start+matched.length(), end, startP+1, endP);
        } else {
            int endPoint = end;
            for (int i=endP; i>startP; i--) {
                endPoint -= smap[pattern[i]-'a'].empty() ? 1 : smap[pattern[i]-'a'].length();
            }
            for (int i=start; i<=endPoint; i++) {
                matched = str.substr(start, i+1-start);
                if (hset.find(matched) != hset.end()) {
                    continue;
                }
                smap[ch-'a'] = matched;
                hset.insert(matched);
                
                if (wordPatternMatch(pattern, str, smap, hset, i+1, end, startP+1, endP)) {
                    return true;
                } else {
                    smap[ch-'a'] = "";
                    hset.erase(matched);
                }
            }
        }
        return false;
    }    
};
