//my first solution which will lead to TLE , this is a brutal force solution which is no any help for dp top down approach
class Solution {
public:
    void go (int start, int end, int& front, int& back, string s, int len, int& ans) {
        if (len > ans) {
            ans = len;
            front = start-1;back = end+1;
        }
        if (start >= end) {
            return;
        }
        for (int i = start; i < end; ++i) {
            for (int j = end; j > start; --j) {
                if (i < j && s[i] == s[j]) {
                    //cout <<i <<" , "<<j << " match "<<s[i] << endl;
                    go (i+1,j-1,front,back,s,len+2,ans);
                }
            }
        }
    }
    int longestPalindromeSubseq(string s) {
        if(s.size() == 0)return 0;
        int ans = 1, front = 0, back = 0;
        go (0,s.size()-1,front, back, s,0,ans);
        //cout << back <<" , "<< front << endl;
        if (back-front > 1) return ans+1;
        return ans;
    }
};
//the dp top down solution after refer to others concept to find out the relationship between 2 substring this solution will lead to memory limit ... maybe there is too much call to sub function
class Solution {
public:
    int go (int i, int j, string s, int** dp) {
        if (dp[i][j] > -1) return dp[i][j];
        //cout <<i <<" , "<<j << endl;
        if (i > j) return 0;
        if (i == j) return 1;
        if (s[i] == s[j]) {
            dp[i][j] = go(i+1,j-1,s,dp)+2;
        } else {
            dp[i][j] = max(go(i+1,j,s,dp), go(i, j-1, s, dp));
        }
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        if(s.size() == 0) return 0;
        int** dp = new int*[s.size()];
        for (int i = 0; i < s.size(); i++) {
            dp[i] = new int[s.size()];
            for (int j = 0; j < s.size(); j++) {
                dp[i][j] = -1;
            }
        }
        return go (0,s.size()-1,s,dp);
    }
};
/*
dp[i][j]: the longest palindromic subsequence's length of substring(i, j), here i, j represent left, right indexes in the string
State transition:
dp[i][j] = dp[i+1][j-1] + 2 if s.charAt(i) == s.charAt(j)
otherwise, dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1])
Initialization: dp[i][i] = 1
*/
public class Solution {
    public int longestPalindromeSubseq(String s) {
        int[][] dp = new int[s.length()][s.length()];

        for (int i = s.length() - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < s.length(); j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.length()-1];
    }
}
Top bottom recursive method with memoization

public class Solution {
    public int longestPalindromeSubseq(String s) {
        return helper(s, 0, s.length() - 1, new Integer[s.length()][s.length()]);
    }

    private int helper(String s, int i, int j, Integer[][] memo) {
        if (memo[i][j] != null) {
            return memo[i][j];
        }
        if (i > j)      return 0;
        if (i == j)     return 1;

        if (s.charAt(i) == s.charAt(j)) {
            memo[i][j] = helper(s, i + 1, j - 1, memo) + 2;
        } else {
            memo[i][j] = Math.max(helper(s, i + 1, j, memo), helper(s, i, j - 1, memo));
        }
        return memo[i][j];
    }
}
//28 ms solution

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<int> dp(size, 1);

        for(int l=size-2; l>=0; l--) {
            int prev = 0;
            int cur = 0;
            for(int r=l+1; r<size; r++) {
                cur = dp[r];
                if(s[l]==s[r])
                    dp[r] = prev + 2;
                else
                    dp[r]= max(dp[r], dp[r-1]);
                prev = cur;
            }
        }
        return dp[size-1];
    }
};
