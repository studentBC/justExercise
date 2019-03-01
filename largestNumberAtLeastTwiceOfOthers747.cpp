class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        vector<int>temp(nums.begin(),nums.end());
        int max = INT_MIN, index;
        for (int i = 0; i < nums.size(); i++) {
            if (max < nums[i]) {
                max = nums[i];
                index = i;
            }
        }
        sort(temp.begin(), temp.end(),greater<int>());
        if (temp[1] == 0) {
            return index;
        } else {
            if (temp[0] == 0) {
                return index;
            } else if (temp[0] > 0 && temp[1] < 0) {
                return index;
            } else if (temp[0] > 0 && temp[0]/temp[1] > 1) {
                return index;
            } else if (temp[0] < 0 ) {
                return index;
            } else {
                return -1;
            }
        }
    }
};

