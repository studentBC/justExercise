class Solution {
public:
    int go (int i, int j, string& s, int** dp) {
        if (i == j) {
            return 1;
        } else if (dp[i][j] > -1) {
            return dp[i][j];
        } else if (s[i] == s[j] && i + 1 == j) {
            return 2; 
        }
        if (s[i] == s[j]) {
            dp[i][j] = go (i+1, j-1, s, dp)+2;
        } else {
            dp[i][j] = max(go(i+1, j, s, dp), go(i, j-1, s, dp));
        }
        //cout <<i<<" , "<<j <<" : "<< dp[i][j] << endl;
        return dp[i][j];
    }
    bool isValidPalindrome(string s, int k) {
        int** dp = new int* [s.size()];
        for (int i = 0; i < s.size(); i++) {
            dp[i] = new int[s.size()];
            for (int j = 0; j < s.size(); j++) dp[i][j] = -1;
        }
        go(0, s.size()-1, s, dp);
       // cout << dp.back().back();
        return s.size()-dp[0][s.size()-1] <= k;
    }
};
//the fatest solution
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
           int j = s.length()-1, ans =0;
        for(int i=0; i<=s.length()/2; i++)
        {
            if(s[i]!=s[j])
            {
                ans++;
            }
            else
               j--;
        }
        int i=0, ans1;
        j = s.length()-1, ans1 =0;
        while( i<s.length()/2 && j>0)
        {
            if(s[i]!=s[j])
            {
                ans1++;
            }
            else
               i++;
            
            j--;
        }
        
        
        if(min(ans, ans1) <=k)
            return true;
        
        return false;
    }
};
