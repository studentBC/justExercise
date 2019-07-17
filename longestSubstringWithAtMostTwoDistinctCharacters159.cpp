/*
 * Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.

Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
 */
class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		if (s.size() == 0) return 0;
		if (s.size() == 1) return 1;
		int l = 0, distinct = 0, i = 0, ans = 0;
		int alpha[58] = {0};
		while (i < s.size()) {
			if (distinct < 2) {
				if (alpha[s[i]-'A'] == 0) {
					distinct++;
				}
			} else {
				if (alpha[s[i]-'A'] == 0) {
					distinct++;
					while (distinct == 3 && l < s.size()) {
						//cout << l <<" , " << alpha[s[l]-'A'] << " ##  ";
						alpha[s[l]-'A']--;
						if (alpha[s[l]-'A'] <= 0) distinct--;
						l++;
					}
				}
			}
			ans = max (ans, i-l+1);
			alpha[s[i]-'A']++;
			i++;
		}
		return ans;
	}
};
//the fatest method
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string str) {
        
        vector<int> counts(128, 0);
        
        size_t e = 0, s = 0;
        int count = 0, numUnique = 0;
        int maxlen = 0;
        while(e < str.size()) {
            ++counts[str[e]];
            if (counts[str[e]] == 1)
                ++numUnique;
            ++e;
            //if (e - s > maxlen)
              //  std::cout << "S=" << s << ",E=" << e << "\n";
            if (numUnique <= 2)
                maxlen = max<int>( maxlen, e - s);
            while (numUnique > 2 && s <= e) {
                if(--counts[str[s++]] == 0)
                    --numUnique;
            }
        }
        return maxlen;
    }
};
