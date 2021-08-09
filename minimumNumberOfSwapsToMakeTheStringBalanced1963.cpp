class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        stack<char>bracket;
        for (char c : s) {
            if (c == '[') {
                bracket.push(c);
            } else {
                if (!bracket.empty()) bracket.pop();
                else ans++;
            }
        }
        
        return (ans+1)/2;
    }
};
