class Solution {
public:
    bool checkPerfectNumber(int num) {
        int half = num>>1, sum = 0;
        if (num == 1) return false;
        for (int i = 2; i <= half; i++) {
            if (num%i == 0) {
                sum+=i;
            }
        }
        return sum+1 == num;
    }
};
//the fatest method just list all answer ...
class Solution {
public:
    bool checkPerfectNumber(int num) {
        return num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336;
    }
};
