/*
 * From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.



Example 1:

Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".

Example 2:

Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.

Example 3:

Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".



Note:

    Both the source and target strings consist of only lowercase English letters from "a"-"z".
    The lengths of source and target string are between 1 and 1000.

wrong test case:
"aaaaa"
"aaaaaaaaaaaaa"

"adbsc"
"addddddddddddsbc"

"aab"
"aabaab"

 */
class Solution {
public:
    int shortestWay(string source, string target) {
        //vector<vector<int>>dp (source.size(), vector<int>(target.size(),-1));
        int start = 0, ans = 1, found = 0, i = 0;
        while ( i < target.size()) {
            found = 0;
            if (start == source.size()) {
                ans++;
                start = 0;
                found = 1;
            }
            for (int j = start; j < source.size(); ++j) {
                if (target[i] == source[j]) {
                    start = j+1;
                    found = 2;
                    break;
                }
                start = j;
            }
            if (!found) {
				start = source.size();
			} else if (found == 1) {
				return -1;
			} else {
				i++;
			}
        }
        return ans;
    }
};
//the fatest method
//Idea is to find the longest subsequence from source, that is part of target substring. : O(n^2)
class Solution {
public:
    int shortestWay(string source, string target) {
        int cnt = 0;
        for (int i = 0; i < target.size();) {
            int k = i;
            for (int j = 0; j < source.size(); j++) {
                if (target[i] == source[j]) {
                    i++;
                }
            }
            if (i == k) {
                return -1;
            }
            cnt++;
        }
        return cnt;
    }
};
