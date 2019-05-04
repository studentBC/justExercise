class Solution {
public:
    bool check (string s) {
        int mid = s.size()>>1;
        for (int i = 0,k=s.size()-1; i < mid; i++,k--) {
            if (s[i]!=s[k])return false;
        }
        return true;
    }
    void go (int start, string s, vector<string>& line, vector<vector<string>>& ans) {
        if (start >= s.size()) {
            ans.emplace_back(line);
        } else {
            string temp = "";
            for (int i = start; i < s.size(); i++) {
                temp+=s[i];
                if (check(temp)) {
                    line.emplace_back(temp);
                    go (i+1,s,line,ans);
                    line.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>line;
        go (0,s,line,ans);
        return ans;
    }
};
//the fatest method
class Solution {
public:
	std::vector<std::vector<std::string>> partition(std::string s)
	{
		std::vector<std::vector<std::string>> res;
		int len = (int)s.length();
		if (len == 0) return res;

		std::vector<std::string> path;
		partition(s, len, 0, path, res);

		return res;
	}

	void partition(std::string& s, int len, int index,
		std::vector<std::string>& path, std::vector<std::vector<std::string>>& res)
	{
		if (index == len)
		{
			res.push_back(path);
			return;
		}

		for (int i = index; i < len; i++)
		{
			if (isPalindrome(s, index, i))
			{
				path.push_back(s.substr(index, i - index + 1));
				partition(s, len, i + 1, path, res);
				path.pop_back();
			}
		}
	}

	bool isPalindrome(std::string& s, int start, int stop)
	{
		while (start < stop)
		{
			if (s[start] != s[stop]) return false;
			start++; stop--;
		}
		return true;
	}
};
