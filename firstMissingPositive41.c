class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            while (nums[i] > 0 && nums[i] <= len && nums[nums[i]-1]!=nums[i]) swap(nums[nums[i]-1], nums[i]); 
        }
        for (int i = 0; i < len; i++) {
            if (nums[i]!=i+1) return i+1;
        }
        return len+1;
    }
};

int firstMissingPositive(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 1;
    } 
    bool temp[numsSize];
    int min = 0, max = -1;
    for (int i = 0; i < numsSize; i++) {
        temp[i] = false; 
        if (max < nums[i]) {
            max = nums[i];
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < numsSize && nums[i] > 0) {
            temp[nums[i]] = true;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if ( !temp[i] && i > min) {
            return i;
        } 
    }
    if (numsSize == max) {
        return max+1;
    }
    return numsSize;
}
