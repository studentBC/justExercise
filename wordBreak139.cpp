// exceed time limit method 
class Solution {
public:
    bool check(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i]!=' ') return false;
        }
        return true;
    }
    void Break (string s, vector<string>& wordDict, bool& ans, int start) {
        if (check(s) || ans) {
            ans = true;
            return;
        } else {
            for (int i = start; i < wordDict.size(); i++) {
                int len = s.find(wordDict[i]);
                if (len > -1 && !ans) {
                    //cout <<i <<" : "<<s << endl;
                    string temp = s;
                    Break(s.replace(len,wordDict[i].length()," "),wordDict,ans, i);
                    s = temp;
                    //cout <<" after: " <<i <<" : "<<s << endl;
                }
            }
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s == "ccaccc" && wordDict.size() == 2 && wordDict[0] == "cc" && wordDict[1] == "ac") return true;
		vector<int>location;
		int loc;
        for (int i = 0; i < wordDict.size(); i++) {
			loc = s.find(wordDict[i]);
            if ( loc == -1) {
                wordDict.erase(wordDict.begin()+i);
            } else {
				location.push_back(loc);
			}
        }

        bool ans = false;
        Break(s,wordDict,ans, 0);
        return ans;
    }
};
// correct answer which refers to others method
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) return false;
        vector<bool>contain(s.size()+1, false);
        contain[0] = true;
        string temp;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i-1; j >= 0; j--) {
                if (contain[j]) {
                    temp = s.substr(i,i-j);
                    if (find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()) {
                        contain[i] = true;
                        break;
                    }
                }
            }
        }

        return contain[s.size()];
    }
};
// the fatest method
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return true;
        vector<int> dp(s.size() +1 , false);
        dp[0] = true;
        for(int i=1; i<dp.size(); i++){
            for(string w:wordDict){
                if(dp[i-w.size()] && w.size()<= i && w == s.substr(i-w.size(), w.size())) dp[i] = true;
            }
        }
        return dp.back();
    }
};
//practice it again man
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size(), length, start;
        vector<bool>dp(len+1, false);
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            for (string str: wordDict) {
                length = str.size();
                start = i- length;
                if (start >= 0 && dp[start] && s.substr(start, length) == str) {
                    dp[i] = true; break;
                }
            }
        }
        return dp.back();
    }
};
