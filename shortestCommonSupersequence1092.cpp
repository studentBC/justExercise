class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        if (str1.size() == 0 && str2.size() == 0) {
            return "";
        } else if (str1.size() == 0 && str2.size() != 0) {
            return str2;
        } else if (str1.size() != 0 && str2.size() == 0) {
            return str1;
        }

        int dp[str1.size()+1][str2.size()+1] = {0};
        dp[0][0] = 0;
        for (int i = 0; i <= str1.size(); i++) {
            for (int j = 0; j <= str2.size(); j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                //cout <<dp[i][j] <<" , ";
            }
            //cout << endl;
        }
        int len = dp[str1.size()-1][str2.size()-1]+1;
        string lcs = "";
        // Start from the right-most-bottom-most corner and
        // one by one store characters in lcs[]
        int i = str1.size(), j = str2.size();
        while (i > 0 && j > 0)
        {
          // If current character in X[] and Y are same, then
          // current character is part of LCS
          if (str1[i-1] == str2[j-1])
          {
              i--; j--;     // reduce values of i, j and index
              //cout <<"meet  " <<i <<" , "<<j<<" : "<< str1[i] << endl;
              lcs += str1[i]; // Put current character in result
          }

          // If not same, then find the larger of two and
          // go in the direction of larger value
          else if (dp[i-1][j] > dp[i][j-1]) {
             i--;
             lcs+=str1[i];
             //cout <<"go up " <<i<<" , "<<j<<" : "<< str1[i] << endl;
          } else {
             j--;
             lcs+=str2[j];
             //cout <<"go left " <<i <<" , "<<j<<" : "<< str2[j] << endl;
          }
        }
        //cout <<i <<" , " << j << endl;
        
        while (i) {
            lcs+=str1[i-1];
            i--;
        }
        while (j) {
            lcs+=str2[j-1];
            j--;
        }
        reverse(lcs.begin(),lcs.end());
        return lcs;
    }
};
//the fatest method
class Solution {
public:
    
    string printShortestSuperSeq(string X, string Y)
    {
        int m = X.length();
        int n = Y.length();

        // dp[i][j] contains length of shortest supersequence
        // for X[0..i-1] and Y[0..j-1]
        int dp[m + 1][n + 1];

        // Fill table in bottom up manner
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                // Below steps follow recurrence relation
                if(i == 0)
                    dp[i][j] = j;
                else if(j == 0)
                    dp[i][j] = i;
                else if(X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Following code is used to print shortest supersequence

        // dp[m][n] stores the length of the shortest supersequence
        // of X and Y
        int index = dp[m][n];

        // string to store the shortest supersequence
        string str;

        // Start from the bottom right corner and one by one
        // push characters in output string
        int i = m, j = n;
        while (i > 0 && j > 0)
        {
            // If current character in X and Y are same, then
            // current character is part of shortest supersequence
            if (X[i - 1] == Y[j - 1])
            {
                // Put current character in result
                str.push_back(X[i - 1]);

                // reduce values of i, j and index
                i--, j--, index--;
            }

            // If current character in X and Y are different
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                // Put current character of Y in result
                str.push_back(Y[j - 1]);

                // reduce values of j and index
                j--, index--;
            }
            else
            {
                // Put current character of X in result
                str.push_back(X[i - 1]);

                // reduce values of i and index
                i--, index--;
            }
        }

        // If Y reaches its end, put remaining characters
        // of X in the result string
        while (i > 0)
        {
            str.push_back(X[i - 1]);
            i--, index--;
        }

        // If X reaches its end, put remaining characters
        // of Y in the result string
        while (j > 0)
        {
            str.push_back(Y[j - 1]);
            j--, index--;
        }

        // reverse the string and return it
        reverse(str.begin(), str.end());
        return str;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        return printShortestSuperSeq(str1 , str2);
    }
};
