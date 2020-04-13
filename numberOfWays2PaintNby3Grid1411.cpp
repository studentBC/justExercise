/*
Explanation

Two pattern for each row, 121 and 123.
121, the first color same as the third in a row.
123, one row has three different colors.

We consider the state of the first row,
pattern 121: 121, 131, 212, 232, 313, 323.
pattern 123: 123, 132, 213, 231, 312, 321.
So we initialize a121 = 6, a123 = 6.

We consider the next possible for each pattern:
Patter 121 can be followed by: 212, 213, 232, 312, 313
Patter 123 can be followed by: 212, 231, 312, 232

121 => three 121, two 123
123 => two 121, two 123

So we can write this dynamic programming transform equation:
b121 = a121 * 3 + a123 * 2
b123 = a121 * 2 + a123 * 2

We calculate the result iteratively
and finally return the sum of both pattern a121 + a123

    int numOfWays(int n) {
        long a121 = 6, a123 = 6, b121, b123, mod = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            b121 = a121 * 3 + a123 * 2;
            b123 = a121 * 2 + a123 * 2;
            a121 = b121 % mod;
            a123 = b123 % mod;
        }
        return (a121 + a123) % mod;
    }
*/
class Solution {
public:
    int numOfWays(int n) {
        long same1 = 6, diff1 = 6, same2, diff2;
		for (int i = 1; i < n; i++) {
			same2 = same1*3+diff*2;
			diff2 = same1*2+diff1*2;
			same1 = same2%mod;
			diff1 = diff2%mod;
		}
		return (same1+diff1)%mod;
    }
};


