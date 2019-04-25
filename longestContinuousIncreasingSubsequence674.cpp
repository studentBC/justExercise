class Solution {
public: 
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 0, prev = INT_MIN, ans = 0;
        for (int i:nums) {
            if (i>prev) {
                count++;
                if (count > ans) ans = count;
            } else {
                count = 1;
            }
            prev = i;
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int curLen = 1;
        int ans = 1;
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                ++curLen;
            } else {
                curLen = 1;
            }
            
            ans = std::max(curLen, ans);
        }
        
        return ans;
    }
};
