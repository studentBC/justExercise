class Solution {
public:
    void go (int start, vector<char>&temp, string S, set<string>&unique) {
        if (temp.size() == S.size()) {
            unique.insert(S);
            return;
        } else {
            for (int i = start; i < S.size(); i++) {
                temp.push_back(S[i]);
                go (i+1, temp, S, unique);
                temp.pop_back();
                S[i] = toupper(S[i]);
                unique.insert(S);
                //cout <<S <<  "  i : "<< i << endl;
            }
        }
        
    }
    vector<string> letterCasePermutation(string S) {
        vector<string>ans;
        if (S.size() == 0) {
            ans.push_back("");
            return ans;
        } else {
			for (int i = 0; i < S.size(); i++) {
				S[i] = tolower(S[i]);
			}
		}
        vector<char>temp;
        set<string>unique;
        go (0,temp,S,unique);
        for (auto it = unique.begin(); it!=unique.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res = {""};
        locale loc;
        int n = S.size();
        for (int i = 0; i < n; i++)
        {
            if (isalpha(S[i], loc))
            {
                char l = tolower(S[i], loc);
                char u = toupper(S[i], loc);
                
                int m = res.size();
                for (int j = 0; j < m; j++)
                {
                    string & s = res[j];
                    string uppercase = s + u;
                    s += l;
                    res.emplace_back(uppercase);
                }
            }
            else
            {
                for (auto & s: res)
                    s += S[i];
            }
        }
        return res;
      }
};
//easily read method
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
       vector <string> result;

        perm(result, S, 0);

        return result;
    }


    void perm(vector<string> &store, string s, int index) {
        if (index == s.length()) {
            store.push_back(s);
            return;
        }

        perm(store, s, index+1);

            if (isalpha(s[index])) {
                if (isupper(s[index])) {
                    s[index] = tolower(s[index]);
                } else {
                    s[index] = toupper(s[index]);
                }
            perm(store, s, index+1);
            }
    }
};
