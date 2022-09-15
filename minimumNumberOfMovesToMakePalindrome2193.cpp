/*
Considering the first and the last char in final palindrome.
If they are neither the first nor the last char in the initial string,
you must waste some steps:
Assume start with "...a....a.."
".a.......a." can be ealier completed thand "a.........a".

Then compare the situation "a....b..a...b"
It takes same number of steps to "ab.........ba" and "ba.........ab".
So we can actually greedy move the characters to match string prefix.
*/
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0, pos;
        while (s.size()) {
            pos = s.find(s.back());
            if (pos == s.size()-1) {
                ans+= pos/2;
            } else {
                s.erase(pos, 1);
                ans+=pos;
            }
            s.pop_back();
        }
        return ans;
    }
};
