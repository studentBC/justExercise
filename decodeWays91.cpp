class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0)return 0;
        vector<int>dp(s.size()+1,0);
        if (s[0] == '0') {
            dp[0] = 0;
        } else {
            dp[0] = 1;
        }
        int roll = 0;
        for (int i = 1; i < s.size(); i++) {
            roll = 10*(s[i-1]-'0')+(s[i]-'0');
            if (roll == 0)return 0;
            if (roll < 27 && roll%10!=0 && s[i-1]!='0') {
                if (i == 1) {
                    dp[i] = dp[i-1]+1;
                } else {
                    dp[i] = dp[i-1]+dp[i-2];
                }
            } else if (roll > 26 && roll%10 == 0) {
                return 0;
            } else if (roll < 27 && roll%10 == 0 && i>1) {
                dp[i] = dp[i-2];
            } else {
                dp[i] = dp[i-1];
            }
            //cout << dp[i] << " , ";
        }
        return dp[s.size()-1];
    }
};
//my fatest solution
class Solution {
public:
    
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int len = s.size(), prev = -1;
        vector<int>num, dp{1};
        for (char c : s) {
            num.push_back(c-'0');
            if (prev == 0 && prev == num.back()) return 0;
            prev = num.back();
        }
        //cout << start << endl;
        for (int i = 1; i < len; i++) {
            if (num[i] == 0) {
                if (i < 2) {
                    if (num[i-1] < 3) dp.push_back(1);
                    else dp.push_back(0);
                } else {
                    if (num[i-1]*10 < 27) dp.push_back(dp[i-2]);
                    else dp.push_back(0);
                }
            } else {
                if (num[i-1] == 0) {
                    dp.push_back(dp.back());
                } else if (num[i-1]*10+num[i] < 27) {
                    if (i > 1) dp.push_back(dp.back()+dp[i-2]);
                    else dp.push_back(dp.back()+1);
                } else dp.push_back(dp.back());
            } 
        }
        return dp.back();
    }
};
