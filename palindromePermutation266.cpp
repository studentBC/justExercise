/*
 * Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true

wrong test case:
"AaBb//a"
 */
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int alpha[128] = {0};
        for (char c:s) {
            alpha[(int)c]++;
        }
        int odd = 0;
        for (int i : alpha) {
            if (i%2) odd++;
        }
        if (odd > 1) {
            return false;
        } else if ( odd == 1) {
            return s.size()%2 == 1;
        } else {
            return s.size()%2 == 0;
        }
    }
};
//the fatest method
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> odd_char = {false};
        for (char c : s) odd_char[c] = !odd_char[c];
        return odd_char.count() < 2;
    }
};
