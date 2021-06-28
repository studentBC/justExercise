class Solution {
public:
    int balancedString(string s) {
        int limit = s.size()/4, len = s.size(), ans = len, j = 0;
        unordered_map<char,int>count;
		for (char c : s) count[c]++;

		for (int i = 0; i < len; i++) {
			count[s[i]]--;
			while (j < len && count['Q'] <= limit && count['W'] <= limit && count['E'] <= limit && count['R'] <= limit ) {
				ans = min(ans, i-j+1);
				count[s[j++]]++;
			}
		}

        return ans;
            
    }
};
