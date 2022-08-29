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
/*
Intuition

Let's work on a simpler problem: T = 'ab'. Whenever we find some 'b' in S, we look for the most recent 'a' that occurred before it, and that forms a candidate window 'a' = S[i], ..., S[j] = 'b'.

A weak solution to that problem would be to just search for 'a' every time we find a 'b'. With a string like 'abbb...bb' this would be inefficient. A better approach is to remember the last 'a' seen. Then when we see a 'b', we know the start of the window is where we last saw 'a', and the end of the window is where we are now.

How can we extend this approach to say, T = 'abc'? Whenever we find some 'c' in S, such as S[k] = 'c', we can remember the most recent window that ended at 'b', let's say [i, j]. Then our candidate window (that is, the smallest possible window ending at k) would be [i, k].

Our approach in general works this way. We add characters to T one at a time, and for every S[k] = T[-1] we always remember the length of the candidate window ending at k. We can calculate this using knowledge of the length of the previous window (so we'll need to remember the last window seen). This leads to a dynamic programming solution.

Algorithm

As we iterate through T[j], let's maintain cur[e] = s as the largest index such that T[:j] is a subsequence of S[s: e+1], (or -1 if impossible.) Now we want to find new, the largest indexes for T[:j+1].

To update our knowledge as j += 1, if S[i] == T[j], then last (the largest s we have seen so far) represents a new valid window [s, i].

In Python, we use cur and new, while in Java we use dp[j] and dp[~j] to keep track of the last two rows of our dynamic programming.

At the end, we look at all the windows we have and choose the best.
*/ 
