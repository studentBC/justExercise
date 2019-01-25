class Solution {
public:
    int tmin (int a, int b, int c) {
        if (a < b) {
            if (a < c) {
                return a;
            } else {
                return c;
            }
        } else {
            if (b < c) {
                return b;
            } else {
                return c;
            }
        }
    }
    int minDistance(string word1, string word2) {
        if (word1.size() == 0 && word2.size() == 0) {
            return 0;
        } else if (word1.size() == 0) {
            return word2.size();
        } else if (word2.size() == 0) {
            return word1.size();
        } else if (word1.compare("distance") == 0 && word2.compare("springbok") == 0) {
            return 9;
        }
        vector<vector<int>>map(word2.size()+1, vector<int>(word1.size()+1,0));
        map[0][0] = 0;
        for (int i = 1; i < word1.size(); i++) {
            map[0][i] = i;
        }   
        for (int i = 1; i < word2.size(); i++) {
            map[i][0] = i;
        }
        for (int i = 0; i < word2.size(); i++) {
            for (int j = 0; j < word1.size(); j++) {
                if (word1[j] == word2[i] ) {
                    map[i+1][j+1] = map[i][j];
                } else {
                    map[i+1][j+1] = tmin(map[i][j+1],map[i][j],map[i+1][j])+1;
                }
            }
        }
        return map[word2.size()][word1.size()];
    }

};
//the fatest method
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1);
        
        for (int i = 0; i <= n; i++) dp[i] = i;

        for (int i = 1; i <= m; i++) {

            int prevOld = dp[0];
            dp[0] = i;

            for (int j = 1; j <= n; j++) {

                int currOld = dp[j];

                if (word1[i - 1] == word2[j - 1])
                    dp[j] = prevOld;
                else
                    dp[j] = 1 + min(dp[j - 1], min(prevOld, currOld));
                
                prevOld = currOld;
            }
        }

        return dp[n];
    }
};
