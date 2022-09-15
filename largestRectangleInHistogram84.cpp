class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, len = heights.size();
        vector<int>left(len, -1), right(len, len);
        vector<int>s;
        for (int i = 0; i < len; i++) {
            while (!s.empty() && heights[s.back()] > heights[i]) {
                right[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        s.clear();
        for (int i = len-1; i > -1; i--) {
            while (!s.empty() && heights[s.back()] > heights[i]) {
                left[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        for (int i = 0; i < len; i++) {
            //cout << left[i] <<" , " << right[i]<<endl;
            ans = max(ans, heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};
