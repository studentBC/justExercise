class Solution {
public:
    int walk[5] = {0,1,0,-1,0};
    void go (int i, int j, int target, int prev, vector<vector<bool>>& bee2, vector<vector<int>>& heights, bool& reach) {
        if (reach || i < 0 || i >=heights.size() || j < 0 || j >=heights[0].size() || bee2[i][j] || abs(heights[i][j]-prev) > target) return;
        //cout <<i <<" , " << j << endl;
        bee2[i][j] = true;
        if (i+1 == heights.size() && j+1 ==heights[0].size()) {
            reach = true;
            return;
        }

        for (int a = 0; a < 4; a++) {
            go (i+walk[a], j+walk[a+1], target, heights[i][j], bee2, heights, reach);
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = INT_MAX, big = -1, small = INT_MAX, right, left = 0, mid;
        if (heights.size() ==1 && heights[0].size() == 1) return 0;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                big = max(big, heights[i][j]);
                small = min(small, heights[i][j]);
            }
        }
        right = big-small;
        bool reach;
        while (left <= right) {
            mid = (left+right)/2;
            reach = false;
            vector<vector<bool>>bee2(heights.size(), vector<bool>(heights[0].size(), false));
            //cout << mid << endl;
            go (0, 0, mid, heights[0][0], bee2, heights, reach);
            if (reach) {
                right = mid-1;
                ans = min(ans, mid);
            } else {
                left = mid+1;
            }
        }
        //go (0,0,-1,-1,dp,heights);
        return ans;
    }
};
