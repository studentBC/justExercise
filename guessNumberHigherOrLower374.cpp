// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if (n == 1)return 1;
        long lower = 1 , upper = n, hint, num = n/2,prev;
        while(true) {
            hint = guess(num);
            if (hint == 1) {
                lower = num;
            } else if (hint == -1) {
                upper = num;
            } else {
                return num;
            }
            //cout <<"up: " << upper <<"  lower: " << lower << "  guess: " << num << endl;
            num = (lower+upper)/2;
            if (prev == num) num++;
            prev = num;
        }
    }
};

