/*
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input: 
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.
 

Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].
*/
/*
The basic idea is simple and based on two pointer:
(1) check feasibility,
(2) check optimization.
*/
class Solution {
public:
    string minWindow(string S, string T) {
        int sindex = 0, tindex = 0, slen = S.size(), tlen = T.size(), start = -1, len = slen;
        while (sindex < slen) {
            if (S[sindex] == T[tindex]) {
                if (++tindex == tlen) {
                    int end = sindex+1;
                    while (--tindex >= 0) {
                        while(S[sindex--] != T[tindex]);
                    }
                    ++sindex; ++tindex;
                    if (end-sindex < len) {
                        len = end-sindex;
                        start = sindex;
                    }
                }
            }
            ++sindex;
        }
        return (start == -1?"":S.substr(start, len));
    }
};
/*
dp[i][j] stores the starting index of the substring where T has length i and S has length j.

So dp[i][j would be:
if T[i - 1] == S[j - 1], this means we could borrow the start index from dp[i - 1][j - 1] to make the current substring valid;
else, we only need to borrow the start index from dp[i][j - 1] which could either exist or not.

Finally, go through the last row to find the substring with min length and appears first.
*/
public String minWindow(String S, String T) {
    int m = T.length(), n = S.length();
    int[][] dp = new int[m + 1][n + 1];
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j + 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (T.charAt(i - 1) == S.charAt(j - 1)) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    int start = 0, len = n + 1;
    for (int j = 1; j <= n; j++) {
        if (dp[m][j] != 0) {
            if (j - dp[m][j] + 1 < len) {
                start = dp[m][j] - 1;
                len = j - dp[m][j] + 1;
            }
        }
    }
    return len == n + 1 ? "" : S.substring(start, start + len);
}
