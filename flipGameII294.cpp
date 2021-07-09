/*
Description
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

Example
Example1

Input:  s = "++++"
Output: true
Explanation:
The starting player can guarantee a win by flipping the middle "++" to become "+--+".
Example2

Input: s = "+++++"
Output: false 
Explanation:
The starting player can not win 
"+++--" --> "+----"
"++--+" --> "----+"
*/
class Solution {
public:
    /**
     * @param s: the given string
     * @return: if the starting player can guarantee a win
     */
    int len;
    bool go (string s) {
        for (int i = 0; i < len; i++) {
            if (i+1 < len && s[i] == s[i+1] && s[i] == '+') {
                s[i] = s[i+1] = '-';
                if (!go(s)) return true;
                s[i] = s[i+1] = '+';
            }
        }
		return false;
    }
    bool canWin(string &s) {
        len = s.size();
        return go (s);
    }
};
