class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0, len = matrix[0].size();
        vector<int>high(len,0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (!matrix[i][j]) high[j] = 0;
                else high[j]++;
            }
            vector<int>height(high.begin(), high.end());
            sort(height.begin(), height.end());
            for (int j = 0; j < len; j++) {
                ans = max(ans, height[j] * (len - j));
            }
        }
        return ans;
    }
};
