class Solution {
public:
    long long countVowels(string word) {
        int len = word.size();
        long long ans = 0, tmp;
        for (int i = 0; i < len; i++) {
            if (string("aeiou").find(word[i]) != string::npos) {
                ans += (long long)(i+1)*(long long)(len-i);
            }
        }
        return ans;
    }
};
