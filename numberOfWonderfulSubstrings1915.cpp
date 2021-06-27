//https://leetcode.com/problems/number-of-wonderful-substrings/discuss/1299523/C%2B%2B-Bit-Vector-%2B-Prefix-Parities-(Similar-to-Prefix-Sums)
//https://leetcode.com/problems/number-of-wonderful-substrings/discuss/1299525/Count-bitmasks-with-picture
class Solution {
 public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int>count;         
        count[0] = 1;     
        long long ans = 0;
        int mask = 0;
        for (char c : word) {
            mask^=(1<<(c-'a'));
            for (int i = 0; i < 11; i++) {
                ans+=count[mask^(1<<i)];
            }             
            ans+=count[mask];
            count[mask]++;
        }        
        return ans;
    }
};

