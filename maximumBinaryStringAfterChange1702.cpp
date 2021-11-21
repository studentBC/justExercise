class Solution {
public:
    string maximumBinaryString(string binary) {
        int len = binary.size(), zero = 0, one = 0;
		for (char& c : binary) {
			if (c == '0') zero++;
			else if (zero == 0) one++;
			c = 1;
		}
		if (one < len) s[one+zero-1] = '0';
		return s;
    }
};
