/*
 * Given two strings str1 and str2 of the same length, determine whether you can transform str1 into str2 by doing zero or more conversions.

In one conversion you can convert all occurrences of one character in str1 to any other lowercase English character.

Return true if and only if you can transform str1 into str2.



Example 1:

Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.
Example 2:

Input: str1 = "leetcode", str2 = "codeleet"
Output: false
Explanation: There is no way to transform str1 to str2.


Constraints:

1 <= str1.length == str2.length <= 104
str1 and str2 contain only lowercase English letters.

test case:
"aabaa"
"ccdee"

"abcdefghijklmnopqrstuvwxyz"
"bcdefghijklmnopqrstuvwxyza"

"abcdefghijklmnopqrstuvwxyz"
"bcadefghijklmnopqrstuvwxzz"
 */

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        unordered_map<char, char>dp;
        for (int i = 0; i < str1.size(); i++) {
            if (dp.count(str1[i]) && dp[str1[i]] != str2[i]) return false;
            dp[str1[i]] = str2[i];
        }
        //whenever the conversion mappings make a cyclic linked list, 
        //we must have a temporary character to break the loop. 
        //The temporary character should not be present in the string str1; 
		//otherwise, the other instances of that character in the string str1 will also change.
        return set(str2.begin(), str2.end()).size() < 26; 
        return true;
    }
};
