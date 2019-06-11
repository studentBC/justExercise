class Solution {
public:
    string removeDuplicateLetters(string s) {
		string temp = "";
		int alpha[26] = {0};
		bool used[26] = {false};
 		for (char c: s) alpha[c-'a']++;
		for (char c:s) {
			--alpha[c-'a'];
			if (!used[c-'a']) {
				while (!temp.empty() && temp.back() > c && alpha[temp.back()-'a'] > 0) {
					used[temp.back()-'a'] = false;
					temp.pop_back();
				}
				used[c-'a'] = true;
				temp.push_back(c);
			}
		}
		return temp;
    }
};
//the fatest method
class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<int> remain(26, 0);
		vector<bool> exist(26, false);
		for (int i = 0; i < s.length(); ++i)
			++remain[s[i] - 'a'];

		string result = "";
		for (int i = 0; i < s.length(); ++i) {
			if (!exist[s[i] - 'a']) {
				while (!result.empty() && s[i] < result.back() && remain[result.back() - 'a'] > 0) {
					exist[result.back() - 'a'] = false;
					result.pop_back();
				}
				result.push_back(s[i]);
				exist[s[i] - 'a'] = true;
			}
			--remain[s[i] - 'a'];
		}
		return result;
	}
};
