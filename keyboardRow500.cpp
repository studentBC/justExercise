//beat 96.15%
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int keyboard[] = {1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2};
        int prev;bool same;
        vector<string>ans;
        for (string w:words) {
            prev = keyboard[tolower(w[0])-'a'];
            same = true;
            for (int i = 1; i < w.size(); i++) {
                if (keyboard[tolower(w[i])-'a'] != prev) {
                    same = false;
                }  
            }
            if (same) ans.emplace_back(w);
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		int m[] = { 2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3 };
		vector<string> ans;
		for (int i = 0; i < words.size(); i++) {
			if (words[i].size() == 0)
				continue;
			int now = m[upper(words[i][0])];
			bool is = true;
			for (int j = 1; j < words[i].size(); j++) {
				if (m[upper(words[i][j])] != now) {
					is = false;
					break;
				}
			}
			if (is)
				ans.push_back(words[i]);
		}
		return ans;
	}
	int upper(char a) {
		if (a >= 'a'&&a <= 'z')
			return a - 'a';
		return a - 'A';
	}
};
