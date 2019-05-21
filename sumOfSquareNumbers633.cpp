class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) return true;
        int end = sqrt(c);
        int left;
        double result;
        for (int i = 1; i <= end; i++) {
            left = c - i*i;
            result = sqrt(left);
            if (result - (int)result == 0) return true;
        }
        return false;
    }
};
//the fatest method
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; i <= sqrt(c); i++) {
            int x = sqrt(c - i * i);
            if (x * x + i * i == c) return true;
        }
        return false;
    }
};
