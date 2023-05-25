/*
Given a string s, encode the string such that its encoded length is the shortest.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. k should be a positive integer.

If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return any of them.

 

Example 1:

Input: s = "aaa"
Output: "aaa"
Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.
Example 2:

Input: s = "aaaaa"
Output: "5[a]"
Explanation: "5[a]" is shorter than "aaaaa" by 1 character.
Example 3:

Input: s = "aaaaaaaaaa"
Output: "10[a]"
Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".
 

Constraints:

1 <= s.length <= 150
s consists of only lowercase English letters.


dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]) or if we can find some pattern in string from i to j which will result in more less length.
*/
class Solution {
public:
bool isSubstringRepeated(const std::string& str, const std::string& substring) {
    int strLength = str.length();
    int subLength = substring.length();

    // Ensure that the substring is not longer than the original string
    if (strLength % subLength)
        return false;

    // Create a string by repeating the substring multiple times
    std::string repeatedSub;
    int numRepeats = strLength / subLength;
    for (int i = 0; i < numRepeats; i++) {
        repeatedSub += substring;
    }

    // Check if the repeated substring matches the original string
    return (str == repeatedSub);
}
    string encode(string s) {
        int len = s.size();
        vector<vector<string>>dp(len, vector<string>(len));
        for (int l = 0; l < len; l++) {
            for (int i = 0; i < len-l; i++) {
                int j = i+l;
                string ss = s.substr(i, l+1);
                if (l < 4) dp[i][j] = ss;
                else {
                    dp[i][j] = ss;
                    for (int k = i; k < j; k++) {
                        if ((dp[i][k]+dp[k+1][j]).size() < dp[i][j].size()) {
                            dp[i][j] = dp[i][k]+dp[k+1][j];
                        }
                    }
                    int ssl, rsl;
                    for (int k = 0; k < ss.size(); k++) {
                        string rs = ss.substr(0, k+1);
                        ssl = ss.size();
                        rsl = rs.size();
                        if (rsl && ssl%rsl == 0
                            && isSubstringRepeated(ss, rs) ) {
                                string sss = to_string(ssl/rsl) + "[" + dp[i][i+k]+ "]";
                                if (sss.size() < dp[i][j].size()) dp[i][j] = sss;
                            }
                    }
                }
            }
        }
        return dp[0].back();
    }
};
