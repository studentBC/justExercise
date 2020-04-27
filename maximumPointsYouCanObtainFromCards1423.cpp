class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, ans = 0;
        for (int i = 0; i < cardPoints.size() && i < k; i++) sum+=cardPoints[i];
        ans = max(sum, ans);
        for (int i = k-1, j = cardPoints.size()-1; i > -1; i--, j--) {
            sum-=cardPoints[i];
            sum+=cardPoints[j];
            ans = max(sum, ans);
        }
        return ans;
    }
};
