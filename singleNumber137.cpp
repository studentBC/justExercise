//the fatest method
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i = 0; i < nums.size(); i ++){
            ones = (ones ^ nums[i]) & (~twos);
            twos = (twos ^ nums[i]) & (~ones);
        }
        
        return ones;
    }
}
//my method
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size()-1;
        if (nums[0] != nums[1]) return nums[0];
        if (nums[len]!=nums[len-1]) return nums[len];
        for (int i = 1; i < len; i++) {
            if (nums[i]!=nums[i-1] && nums[i]!=nums[i+1]) {
                return nums[i];
            }
        }
    }
};
