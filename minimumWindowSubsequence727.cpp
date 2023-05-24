/*
Given strings s1 and s2, return the minimum contiguous substring part of s1, so that s2 is a subsequence of the part.

If there is no such window in s1 that covers all characters in s2, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

 

Example 1:

Input: s1 = "abcdebdde", s2 = "bde"
Output: "bcde"
Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of s2 in the window must occur in order.
Example 2:

Input: s1 = "jmeqksfrsdcmsiwvaovztaqenprpvnbstl", s2 = "u"
Output: ""
 

Constraints:

1 <= s1.length <= 2 * 104
1 <= s2.length <= 100
s1 and s2 consist of lowercase English letters.


solution:
dp[i][j] stores the starting index of the substring where T has length i and S has length j.

So dp[i][j would be:
if T[i - 1] == S[j - 1], this means we could borrow the start index from dp[i - 1][j - 1] to make the current substring valid;
else, we only need to borrow the start index from dp[i][j - 1] which could either exist or not.

Finally, go through the last row to find the substring with min length and appears first.
*/
class Solution {
public:
    string minWindow(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        vector<vector<int>>dp(l2+1, vector<int>(l1+1, 0));
        for (int i = 0; i <= l1; i++) dp[0][i] = i+1;
        for (int i = 1; i <= l2; i++) {
            for (int j = 1; j <= l1; j++) {
                if (s2[i-1] == s1[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        int start = 0, len = INT_MAX;
        for (int i = 1; i <= l1; i++) {
            if (dp[l2][i]) {
                if (i-dp[l2][i]+1 < len) {
                    start = dp[l2][i]-1;
                    len = i-dp[l2][i]+1;
                }
            }
        }
        return len == INT_MAX? "" : s1.substr(start, len);
    }
};
