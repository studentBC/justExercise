class Solution {
public:
    int go (int i, vector<vector<int>>& books, int& width, int shelf_width, int heaviest) {
        if (i == -1) {
			return 0;
		}
        if (shelf_width >= books[i][0]) {
            if (heaviest >= books[i][1]) {
                return min(go (i-1,books,width,shelf_width-books[i][0],heaviest), heaviest+go(i-1,books,width,width-books[i][0],books[i][1]));
            } else {
                return min(heaviest+go (i-1,books,width,width-books[i][0],books[i][1]), books[i][1]+go (i-1,books,width,shelf_width-books[i][0],books[i][1]));
            }
        } else {
            return heaviest+go (i-1,books,width,width-books[i][0],books[i][1]);
        }
    }
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int heaviest = 0;
        return go (books.size()-1,books,shelf_width, shelf_width, heaviest);
    }
};
/*dp[i]: the min height for placing first books i - 1 on shelves
For dp[i+1],
either place book i on a new shelve => dp[i] + height[i],
or grab previous books together with book i and move to next level together, utlitzing the sub problem dp[j] => min(dp[j] + max(height[j+1] .. height[i])), where sum(width[j+1] + ... + sum(width[i]) <= shelve_width
*/
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int>dp(books.size()+1,0);
        dp[0] = 0;
        int width, height;
        for (int i = 1; i <= books.size(); ++i) {
            width = books[i-1][0];
			height = books[i-1][1];
            dp[i] = height + dp[i-1];
            for (int j = i-1; j > 0 && width+books[j-1][0] <= shelf_width ; width+=books[j-1][0],--j) {
				height = max (height, books[j-1][1]);
                dp[i] = min (dp[i], dp[j-1]+height);
            }
        }
        return dp.back();
    }
};
//the fatest method
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        int i ;
        int dp[n];
        for(i=0;i<n;i++){
            if(i == 0){
                dp[i] = books[i][1];
            }
            else{
                dp[i] = dp[i-1] + books[i][1];
                int width = books[i][0];
                int maxi = books[i][1];
                int j = i-1;
                while(j>=0 && width + books[j][0]<=shelf_width){
                    maxi = max(maxi, books[j][1]);
                    if(j == 0){
                        dp[i] = min(dp[i], maxi);
                    }
                    else{
                        dp[i] = min(dp[i], dp[j-1]+maxi);
                    }
                    width+=books[j][0];
                    j--;
                }
            }
        }
        return dp[n-1];
    }
};
