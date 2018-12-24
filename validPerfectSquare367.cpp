class Solution {
public:
    bool isPerfectSquare(int num) {
 		if (num < 1) return false;
		int i = sqrt(num);
		int square = i*i;
		if (square==num) return true;
		return false;
    }
};
