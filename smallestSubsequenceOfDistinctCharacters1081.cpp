//beat 76.36% method
class Solution {
public:
    string smallestSubsequence(string text) {
		vector<int>alpha(26,0);
		vector<bool>used(26,false);
		string ans = "";
		for (char c:text) alpha[c-'a']++;
		for (char c:text) {
			alpha[c-'a']--;
			if (!used[c-'a']) {
				while (!ans.empty() && ans.back() > c && alpha[c-'a'] > 0 && alpha[ans.back()-'a'] > 0) {
					used[ans.back()-'a'] = false;
					ans.pop_back();
				}
				ans.push_back(c);
				used[c-'a'] = true;
			}
		}
		return ans;
    }
};
//the fatest method
class Solution {
public:
    string smallestSubsequence(string text) {
        int n = text.size();
        bool use[n];
        string res;
        res += text[0];
        for(int i = 1; i < text.size(); i++){
            if(res.find(text[i]) == string::npos){
            for(int j = res.size()-1; j < res.size();){
                if(text[i] < res[j]){
                    string temp = text.substr(i+1);
                    if(temp.find(res[j]) != string::npos){
                        res.erase(res.begin() + j);
                        j--;
                    }
                    else break;
                }
                else break;
            
            }
            res += text[i];
            cout << res << endl;
            }
        }
        return res;
    }
};
