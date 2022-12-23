/*
 * The key idea of this algorithm goes as follows

1. Start placing books one by one, always use a new shelve to begin with
2. After you stored the new height value at this position in your dp array, start looking back at previous books one by one, and see while the width permits, how many books you can fit on this new level.
3. Check to see if bringing said books down reduced the overall height, if it did, update the new lowest height value at your dp array.
4. return the last element of your dp array
 */
class Solution {
public:
    
    vector<int>dp;
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int len = books.size(), h, w;
        dp.resize(len+1, 0);
        for (int i = 1; i <= len; i++) {
            w = books[i-1][0];
            h = books[i-1][1];
            dp[i] = dp[i-1]+h;
            for (int j = i-1; j > 0 && w + books[j-1][0] <= shelfWidth; j--) {
                h = max(h, books[j-1][1]);
                w+=books[j-1][0];
                dp[i] = min(dp[i], dp[j-1]+h);
            }
        }
        return dp.back();
    }
};
