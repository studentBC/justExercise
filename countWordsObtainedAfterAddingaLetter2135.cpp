class Solution {
public:
        int convert (string s) {
                int ans = 0;
                for (char c : s) ans+=(1<<(c-'a'));
                return ans;
        }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
                unordered_set<int>number;
                for (string& s : startWords) number.insert(convert(s));
                int ans = 0, num, temp;
                for (string s: targetWords) {
                        num = convert(s);
                        for (int i = 0; i < 27; i++) {
                                if ((num & (1<<i)) > 0) {
                                        temp = num-(1<<i);
                                        if (number.count(temp)) {ans++; break;}
                                }
                        }
                }
                return ans;
    }
};


