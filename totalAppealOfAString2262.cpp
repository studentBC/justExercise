class Solution {
public:
    long long appealSum(string s) {
 		vector<int>count(26, 0);
		long long ans = 0;
		for (int i = 0; i < s.size(); i++) {
			count[s[i]-'a'] = i+1;
			for (int j : count) ans+=j;
		}
		return ans;
    }
};
