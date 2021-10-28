class Solution {
public:
    int get (string answerKey, char c, int k) {
        int i = 0, len = answerKey.size(), sum = 0, ans = 0;
        for (int j = 0; j < len; j++) {
            sum+= (answerKey[j] == c);
            while (sum > k) {
                sum-= (answerKey[i] == c);
                i++;
            }
            ans = max(j-i+1, ans);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(get(answerKey, 'T', k), get(answerKey, 'F', k));
    }
};
