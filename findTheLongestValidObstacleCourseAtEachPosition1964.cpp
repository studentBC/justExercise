class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int len = obstacles.size(), left, right, mid;
        vector<int>num, ans;
        for (int i = 0; i < len; i++) {
            if (num.empty() || obstacles[i] >= num.back()) {
                num.push_back(obstacles[i]);
                ans.push_back(num.size());
            } else {
                left = 0; right = num.size();
                while (left<=right) {
                    mid = (left+right)/2;
                    if (num[mid] <= obstacles[i]) {
                        left = mid+1;
                    } else {
                        right = mid-1;
                    }
                }
                num[left] = obstacles[i];
                ans.push_back(left+1);
            }
        }
        return ans;
    }
};
