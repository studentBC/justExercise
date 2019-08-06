class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp (text1.size(), vector<int>(text2.size(), 0));
		for (int j = 0; j < text2.size(); j++) {
			if (text1[0] == text2[j]) {
				dp[0][j] = 1;
			} else {
				if (j > 0)dp[0][j] = dp[0][j-1];
			}
        }
        for (int i = 1; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
				if (text1[i] == text2[j]) {
                	if ( j > 0 ) {
						dp[i][j] = max (dp[i-1][j-1]+1, max(dp[i-1][j], dp[i][j-1]));
					} else if (j == 0 ) {
						dp[i][j] = max(1, dp[i-1][j]);
					}
				} else {
					if (j > 0) {
						dp[i][j] = max (dp[i][j-1], dp[i-1][j]);
					} else {
						dp[i][j] = dp[i-1][j];
					}
				}
            }
        }
            
        return dp.back().back();
    }
};
//the fatest method
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2)
	{
		vector<size_t> text1Pos;
		text1Pos.resize(1, 0);


		for (char c : text2)
		{
			int size = text1Pos.size();

			for (int len = size - 1; len >= 0; --len)
			{
				auto newPos = text1.find(c, text1Pos[len]);

				if (newPos == string::npos) continue;

				++newPos;
				if (text1Pos.size()==len + 1)  text1Pos.push_back(newPos);
				else text1Pos[len + 1] = min(text1Pos[len + 1], newPos);

			}
		}

		return text1Pos.size() - 1;
	}
};
