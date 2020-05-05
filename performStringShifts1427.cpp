/*
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

 

Example 1:

Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"
Example 2:

Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
 

Constraints:

1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100
*/
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        string ans;
        vector<char>alpha;
        for (char c:s) alpha.push_back(c);
        for (auto& it: shift) {
            if (it[0]) {
                for (int i = 0; i < it[1]; i++) {
                    alpha.insert(alpha.begin(), alpha.back());
                    alpha.pop_back();
                }
            } else {
                for (int i = 0; i < it[1]; i++) {
                    alpha.push_back(alpha[0]);
                    alpha.erase(alpha.begin());
                }
            }
        }
        for (char c: alpha) ans.push_back(c);
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int tShift = 0;
        string copy = s + s;
        
        for (auto sh: shift) {
            if (sh[0] == 1) {
                tShift += sh[1];
            } else {
                tShift -= sh[1];
            }
        }

        if (tShift < 0) {
            tShift = ((-1 * tShift) % s.length()) * -1;
        } else {
            tShift = tShift % s.length();
        }

        if (tShift >= 0) {
            copy = copy.substr(s.length() - tShift, s.length());
        } else {
            copy = copy.substr(tShift * -1, s.length());
        }
        
        return copy;
    }
};
