//my first solution , Time Limit cant pass
class Solution {
public:
    bool check (int start, int end, string& s) {
        int one = 0, zero = 0, count = 0;
        char prev = '$';
        for (int i = start; i <= end; i++) {
            if (s[i] == '0') {
                zero++;
            } else {
                one++;
            }  
            if (prev != s[i]) {
                count++;
            }  
            prev = s[i];
        }  
        if (zero == one && count == 2) {
            return true;
        } else {
            return false;
        }
    }
    int countBinarySubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i+1; j < s.size(); j++) {
                if (check(i,j,s))count++;
            }
        }
        return count;
    }
};
/*Intuition

We can convert the string s into an array groups that represents the length of same-character contiguous blocks within the string. For example, if s = "110001111000000", then groups = [2, 3, 4, 6].

For every binary string of the form '0' * k + '1' * k or '1' * k + '0' * k, the middle of this string must occur between two groups.

Let's try to count the number of valid binary strings between groups[i] and groups[i+1]. If we have groups[i] = 2, groups[i+1] = 3, then it represents either "00111" or "11000". We clearly can make min(groups[i], groups[i+1]) valid binary strings within this string. Because the binary digits to the left or right of this string must change at the boundary, our answer can never be larger.

Algorithm

Let's create groups as defined above. The first element of s belongs in it's own group. From then on, each element either doesn't match the previous element, so that it starts a new group of size 1; or it does match, so that the size of the most recent group increases by 1.

Afterwards, we will take the sum of min(groups[i-1], groups[i]).
*/
class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 1, ans = 0;
		s+="#";
		vector<int>group(s.size());
        for (int i = 0; i < s.size(); i++) {
            if (s[i]!=s[i+1]) {
				group.emplace_back(count);
				count = 1;
			} else {
				count++;
			}
        }
		for (int i = 1; i < group.size(); i++) {
			ans+=min(group[i-1],group[i]);
		}
        return ans;
    }
};
//12 ms solution
/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 *
 * https://leetcode.com/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (52.84%)
 * Total Accepted:    29.6K
 * Total Submissions: 55.6K
 * Testcase Example:  '"00110"'
 *
 * Give a string s, count the number of non-empty (contiguous) substrings that
 * have the same number of 0's and 1's, and all the 0's and all the 1's in
 * these substrings are grouped consecutively. 
 * 
 * Substrings that occur multiple times are counted the number of times they
 * occur.
 * 
 * Example 1:
 * 
 * Input: "00110011"
 * Output: 6
 * Explanation: There are 6 substrings that have equal number of consecutive
 * 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
 * Notice that some of these substrings repeat and are counted the number of
 * times they occur.
 * Also, "00110011" is not a valid substring because all the 0's (and 1's) are
 * not grouped together.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "10101"
 * Output: 4
 * Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
 * number of consecutive 1's and 0's.
 * 
 * 
 * 
 * Note:
 * s.length will be between 1 and 50,000.
 * s will only consist of "0" or "1" characters.
 * 
 */
int optimization = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.size() <= 1) return 0;

        int ans = 0;
        vector<int> group;
        int prev = 0;
        int cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] == s[i]) ++cnt;
            else {
                ans += min(prev, cnt);
                prev = cnt;
                cnt = 1;
            }
        }

        return ans + min(prev, cnt);
    }
};

