/*
 * Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.

Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.


 */
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
		int ans = 0, prev = 0, count = 0;
		unordered_map<char,int>distinct;
		unordered_map<char,int>::iterator it;
		for (int i = 0; i < s.size(); i++) {
			it = distinct.find(s[i]);
			if (distinct.size() < k) {
				if (it == distinct.end()) {
					distinct.insert(pair<char,int>(s[i], 1));
				} else {
					it->second++;
				}
				count++;
			} else {
				if (it == distinct.end()) {
					distinct.insert(pair<char,int>(s[i], 1));
					count++;
					while (1) {
						it = distinct.find(s[prev]);
						it->second--;
						count--;
						if (it->second == 0) {
							distinct.erase(s[prev]);
							prev++;
							break;
						}
						prev++;
					}
				} else {
					it->second++;
					count++;
				}
			}
			ans = max(ans,count);
		}
		return ans;
    }
};
//the fatest method
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        int i = 0, j = 0, res = 0, tempcount = 0;
        vector<int> cts(128,0);
        while(j < n) {
            //move j ---->>>
            //find new character
            if(++cts[s[j++]] == 1) {
                ++tempcount;
            }
            if(tempcount <= k) {
                res = max(res, j-i);
            } else {
                ///move i ---->>
                while(tempcount > k) {
                    if(--cts[s[i++]] == 0) {
                        --tempcount;
                    }
                    
                }
            }
            
        }
        return res;
    }
};

static auto _=[](){cin.tie(nullptr);ios::sync_with_stdio(false);return 0;}();
