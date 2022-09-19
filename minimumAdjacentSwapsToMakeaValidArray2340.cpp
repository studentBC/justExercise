class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int small = INT_MAX, big = INT_MIN, bi, si, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (small > nums[i]) {
                si = i;
                small = nums[i];
            }
        }
        for (int i = nums.size()-1; i > -1; i--) {
            if (big < nums[i]) {
                bi = i;
                big = nums[i];
            }
        }
        if (nums.size()-bi-1 > si) {
            ans+=si;
            nums.erase(nums.begin()+si);
            nums.insert(nums.begin(), small);
            big = INT_MIN;
            for (int i = nums.size()-1; i > -1; i--) {
                if (big < nums[i]) {
                    bi = i;
                    big = nums[i];
                }
            }
            ans+=(nums.size()-1-bi);
        } else {
            ans+=(nums.size()-1-bi);
            nums.erase(nums.begin()+bi);
            nums.push_back(big);
            small = INT_MAX;
            for (int i = 0; i < nums.size(); i++) {
                if (small > nums[i]) {
                    si = i;
                    small = nums[i];
                }
            }
            ans+=si;
        }
        return ans;
    }
};
