/*
leetscode, dictionary = ["leet","code","leetcode"]

[l + eetscode]
#Make a cut “l” and fix the string
#Then get the extra character count for “eetscode” (recursion)
#Now “l” is not in dictionary so
totalExtra = sizeof(“l”) + nextExtra(got via recursion)
//====================================================
[le + etscode]
#Make a cut “le” and fix the string
#Then get the extra character count for “etscode” (recursion)
#Noe “le” is not in dictionary
totalExtra = sizeof(“le”) + nextExtra(got via recursion)
//====================================================
[lee + tscode]
#Similarly for “lee”
//================================================================
[leet + scode]
#Make a cut “leet” and fix the string
#Then get the extra character count for “scode” (recursion)
#Now “leet” is in dictionary :) [A relief]
totalExtra = 0 + nextExtra(got via recursion)
//==================================================================
#Similarly other calls are made
*/
class Solution {
public:
    unordered_set<string>mark;
    int len;
    int go (string& s, int index, vector<int>& dp) {
        if (index == len) return 0;
        if (dp[index]!=-1) return dp[index];
        int ans = len, sum = 0;
        string cur = "";
        for (int j = index; j < len; j++) {
            cur.push_back(s[j]);
            int curRedundant = (mark.count(cur))?0:cur.size();
            int nextRedundant = go(s, j+1, dp);
            sum = curRedundant+nextRedundant;
            ans = min(ans, sum);
        }

        return dp[index] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int start = 0;
        len = s.size();
        vector<int>dp(len, -1);
        for (int i = 0; i < dictionary.size(); i++) {
            mark.insert(dictionary[i]);
        }
        return go (s, 0, dp);
    }
};
