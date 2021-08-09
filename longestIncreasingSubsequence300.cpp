class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0, len = nums.size(), left, right, mid;
        vector<int>num;
        for (int i = 0; i < len; i++) {
            if (num.empty() || nums[i] > num.back()) num.push_back(nums[i]);
            else {
                left = 0; right = num.size();
                while (left<=right) {
                    mid = (left+right)/2;
                    if (num[mid] < nums[i]) {
                        left = mid+1;
                    } else {
                        right = mid-1;
                    }
                }
                num[left] = nums[i];
            }
        }
        return num.size();
    }
};
