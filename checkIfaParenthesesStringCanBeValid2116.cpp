/*
A useful trick (when doing any parentheses validation) is to greedily check balance left-to-right, and then right-to-left.

Left-to-right check ensures that we do not have orphan ')' parentheses.
Right-to-left checks for orphan '(' parentheses.
We go left-to-right:

Count wild (not locked) characters.
Track the balance bal for locked parentheses.
If the balance goes negative, we check if we have enough wild characters to compensate.
In the end, check that we have enough wild characters to cover positive balance (open parentheses).
This approach alone, however, will fail for ["))((", "0011"] test case. That is why we also need to do the same going right-to-left.
*/

class Solution {
public:
	bool check (string s, string locked, char op) {
  		int bal = 0, wild = 0, len = s.size();
		int start = op == '(' ? 0 : len-1, dir = op == '(' ? 1 : -1;
		for (int i = start; i > -1 && i < len && wild + bal > -1; i+=dir) {
			if (locked[i] == '1') bal+= s[i] == op? 1: -1;
			else wild++;
		}
		return abs(bal)<=wild;
	}
    bool canBeValid(string s, string locked) {
		return s.size()%2 == 0 && check(s, locked, '(') && check(s, locked, ')');
    }
};

