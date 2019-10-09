/*concept 
Let f(k) = count of numbers with unique digits with length equals k.
f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n > 9) return 8877691;
        int all[10] = {1, 9, 81, 648, 4536, 27216, 136080, 544320, 1632960, 3265920};
        int ans = 0;
        for (int i = 0; i <= n; i++) ans+=all[i];
        return ans;
    }
};
