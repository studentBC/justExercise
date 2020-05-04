class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
 		int most = 0;
		for (int c: candies) most = max(most, c);
		vector<bool>ans;
		for (int c: candies) {
			if (c+extraCandies >= most) ans.push_back(true);
			else ans.push_back(false);
		}
		return ans;
    }
};
