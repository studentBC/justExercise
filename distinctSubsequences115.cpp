//my brutal force method which can pass only 54/63
class Solution {
public:
    void dfs (int i, int j, int& ans, vector<vector<int>>&candidate) {
        if (i+1 == candidate.size()) {
            ans++;
            return;
        }
        //cout  << i << " , " << j << " :  "<< candidate[i+1][j] << endl;
        for (int k = 0; k < candidate[i+1].size(); k++) {
            if (i == -1 || candidate[i+1][k] > candidate[i][j]) {
                dfs (i+1,k,ans,candidate);
            }
        }
        
        return;
    }        
    int numDistinct(string s, string t) {
        vector<vector<int>>alphabet(26,0);
		for (int i = 0; i < s.size(); i++) {
			alphabet[s[i]-'a'].push_back(i);
		}
        vector<vector<int>>candidate;
        for (int i = 0; i < t.size(); i++) {
            candidate.push_back(alphabet[t[i]-'a']);
        }
        int ans = 1;
		for (int i = 0; i < t.size(); i++) {
			ans*=candidate[i].size();
			candidate[i].pop_back();
		}
        return ans;
    }
};
/*
The idea is the following:

we will build an array mem where mem[i+1][j+1] means that S[0..j] contains T[0..i] that many times as distinct subsequences. Therefor the result will be mem[T.length()][S.length()].
we can build this array rows-by-rows:
the first row must be filled with 1. That's because the empty string is a subsequence of any string but only 1 time. So mem[0][j] = 1 for every j. So with this we not only make our lives easier, but we also return correct value if T is an empty string.
the first column of every rows except the first must be 0. This is because an empty string cannot contain a non-empty string as a substring -- the very first item of the array: mem[0][0] = 1, because an empty string contains the empty string 1 time.
So the matrix looks like this:

  S 0123....j
T +----------+
  |1111111111|
0 |0         |
1 |0         |
2 |0         |
. |0         |
. |0         |
i |0         |
From here we can easily fill the whole grid: for each (x, y), we check if S[x] == T[y] we add the previous item and the previous item in the previous row, otherwise we copy the previous item in the same row. The reason is simple:

if the current character in S doesn't equal to current character T, then we have the same number of distinct subsequences as we had without the new character.
if the current character in S equal to the current character T, then the distinct number of subsequences: the number we had before plus the distinct number of subsequences we had with less longer T and less longer S.
An example:
S: [acdabefbc] and T: [ab]

first we check with a:

           *  *
      S = [acdabefbc]
mem[1] = [0111222222]
then we check with ab:

               *  * ]
      S = [acdabefbc]
mem[1] = [0111222222]
mem[2] = [0000022244]
And the result is 4, as the distinct subsequences are:

      S = [a   b    ]
      S = [a      b ]
      S = [   ab    ]
      S = [   a   b ]
*/ 

int numDistinct(string s, string t) {
	vector<vector<unsigned int>>dp(t.size()+1,vector<unsigned int>(s.size()+1,0));
	for (int i = 0; i <= s.size(); i++) {
		dp[0][i] = 1;
	}
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (t[i] == s[j]) {
				dp[i+1][j+1] = dp[i][j] + dp[i+1][j];
			} else {
				dp[i+1][j+1] = dp[i+1][j];
			}
		}
	}
	return dp[t.size()][s.size()];
}
//the fatest method
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long long> ans(t.size() + 1, 0);
        vector <vector<int>> chPos(128);
        int tSize = t.size();
        for (int i = 0; i < tSize; i++)
            chPos[t[i]].push_back(tSize - i);
        ans[0] = 1;
        int sSize = s.size();
        for (int i = sSize; i >= 0; i--) {
            char ch = s[i];
            //避免重复叠加，id大的优先
            for (auto id:chPos[ch]) {
                if(id > sSize - i)
                    continue;
                ans[id] += ans[id - 1];
            }
        }
        return int(ans[t.size()]);
    }
};
