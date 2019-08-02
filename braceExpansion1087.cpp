/*
A string S represents a list of words.

Each letter in the word has 1 or more options.  If there is one option, the letter is represented as is.  If there is more than one option, then curly braces delimit the options.  For example, "{a,b,c}" represents options ["a", "b", "c"].

For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", "cde", "cdf"].

Return all words that can be formed in this manner, in lexicographical order.

 

Example 1:

Input: "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]
Example 2:

Input: "abcd"
Output: ["abcd"]
 

Note:

1 <= S.length <= 50
There are no nested curly brackets.
All characters inside a pair of consecutive opening and ending curly brackets are different.

wrong test case:
"{a,b}"
"{a,b}{z,x,y}"
*/ 
class Solution {
public:
    void go (int i, vector<string>& group, string& temp, vector<string>& ans) {
        if (i == group.size()) {
            ans.emplace_back(temp);
            return;
        }
		//cout <<"start from " << i << endl;
		for (int j = 0; j < group[i].size(); j++) {
			temp.push_back(group[i][j]);
			//cout <<"go " << i <<" , " << j << " : " << group[i][j] <<  endl;
			go (i+1, group, temp, ans);
			temp.pop_back();
			//cout <<"pop back" << endl;
		}
    }
    vector<string> expand(string S) {
 		vector<string>group, ans;
		if (S.back() != '}' )S.push_back('}');
		string temp="";bool comma = false;
		for (char c:S) {
			if (c == '{' || c == '}') {
				if (temp.size()) {
					//cout <<"push back " << temp << endl;
					group.emplace_back(temp);
					temp = "";
				}
			} else if (c != ',') {
				temp.push_back(c);
			} else {
				comma = true;
			}
		}
		if (group.size() < 2) {
			if (comma && S[0] == '{' && S.back() == '}') {
				group.clear();
				S.erase(S.begin());S.pop_back();
				for (char c:S) {
					if (c != ',') {
						temp.push_back(c);
					} else {
						group.emplace_back(temp);
						temp = "";
					}
				}
			}
			return group;
		}
		go (0, group, temp, ans);
		return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<string> expand(string s) {
        int cnt = 0;
        vector<string> res;
        bool brace = false, first = false;
        for (char c : s)
            switch(c) {
                case ',': break;
                case '{':
                    brace = true;
                    first = true;
                    break;
                case '}':
                    brace = false;
                    break;
                default:
                    if (!brace || first) {
                        if (res.empty()) res.push_back(string(1, c));
                        else for (auto& s : res) s.push_back(c);
                        if (first) {
                            first = false;
                            cnt = res.size();
                        }
                    } else
                        for (int i = 0; i < cnt; i++)
                            res.push_back(res[i].substr(0, res[i].size()-1)+c);
                    break;
            }
        sort(res.begin(), res.end());
        return res;
    }
};
//the concept solution
class Solution {
    public String[] expand(String S) {
		// TreeSet to sort
        TreeSet<String> set = new TreeSet<>();
        if (S.length() == 0) {
            return new String[]{""}; 
        } else if (S.length() == 1) {
            return new String[]{S};
        }
        if (S.charAt(0) == '{') {
            int i = 0; // keep track of content in the "{content}"
            while (S.charAt(i) != '}') {
                i++;
            }
            String sub = S.substring(1, i);
            String[] subs = sub.split(",");
            String[] strs = expand(S.substring(i + 1)); // dfs
            for (int j = 0; j < subs.length; j++) {
                for (String str : strs) {
                    set.add(subs[j] + str);
                }
            }
        } else {
            String[] strs = expand(S.substring(1));
            for (String str : strs) {
                set.add(S.charAt(0) + str);
            }
        }
        return set.toArray(new String[0]);
    }
}
