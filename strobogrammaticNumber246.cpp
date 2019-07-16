/*
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true

Example 2:

Input:  "88"
Output: true

Example 3:

Input:  "962"
Output: false
strobogrammatic
0 1 6 8 9 
 */
class Solution {
public:
    bool isStrobogrammatic(string num) {
		int i = num.size()-1;
		for (char c:num) {
			if (c == '0') {
				if (c != num[i]) return false;
			} else if (c == '1') {
				if (c != num[i]) return false;
			} else if (c == '6') {
				if ('9' != num[i]) return false;
			} else if (c == '8') {
				if (c != num[i]) return false;
			} else if (c == '9') {
				if ('6' != num[i]) return false;
			} else {
				return false;
			}
			i--;
		}
		return true;
    }
};
//the fatest method
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> strobogrammatic = {
            {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
        };
        int left = 0, right = num.size()-1;
        while (left <= right) {
            if (strobogrammatic.count(num[left]) == 0 || strobogrammatic[num[left]] != num[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
