class Solution {
public:
    int totalMoney(int n) {
        int sum = 0, count = 1;
        while (n) {
            if (n >= 7) {
                sum += 7 * (3 + count);
                n -= 7;
                count++;
            }
            else {
                for (int i = 0; i < n; i++, count++) {
                    sum += count;
                }
                n = 0;
            }
        }
        return sum;
    }
};
