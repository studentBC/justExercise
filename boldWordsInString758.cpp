/*
Given a set of keywords words and a string S, make all appearances of all keywords in S bold. Any letters between <b> and </b> tags become bold.

The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Note:

words has length in range [0, 50].
words[i] has length in range [1, 10].
S has length in range [0, 500].
All characters in words[i] and S are lowercase letters.

wrong testcase:
["ccb","b","d","cba","dc"]
"eeaadadadc"
*/ 
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
		bool found, end, prev;
		vector<bool>hit(S.size(), false);
  		for (string s:words) {
			for (int i = 0; i < S.size(); i++) {
				if (s[0] == S[i]) {
					found = true;end = false;
					for (int j = i, k = 0; j < S.size() && k < s.size(); j++,k++) {
						if (S[j] != s[k]) {
							found = false;break;
						}
						if (k == s.size()-1) end = true;
					}
					if (found && end) {
						for (int j = i, k = 0; k < s.size(); k++,j++) hit[j] = true;
					}
				}
			}
		}
		prev = false;
		string ans="";
		for (int i = 0; i < S.size(); i++) {
			if (hit[i]) {
				//cout <<i <<" , ";
				if (!prev) ans+="<b>";
				ans.push_back(S[i]);
			} else {
				if (prev) {
					ans+="</b>";
					ans.push_back(S[i]);
				} else {
					ans.push_back(S[i]);
				}
			}
			prev = hit[i];
		}
		if (hit.back())ans+="</b>";
		return ans;
    }
};
//the fatest method
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        
        vector<bool> isBold(S.size());
        for_each(words.begin(), words.end(), [&](string const& word) {
            std::size_t found = S.find(word);
            while (found != string::npos) {
                for (size_t i = found; i < found + word.size(); ++i) {
                   isBold[i] = true; 
                }
                found = S.find(word, found+1);
            }
        });
        
        string boldS;
        
        for (size_t i = 0; i < S.size(); ++i) {
            if (isBold[i] == true && (i == 0 || isBold[i-1] == false)) {
                boldS.append("<b>");
            }
                
            boldS.push_back(S[i]);
                
            if (isBold[i] == true && (i == S.size()-1 || isBold[i+1] == false)){
                boldS.append("</b>");
            }
        }
        return boldS;
    }
};
