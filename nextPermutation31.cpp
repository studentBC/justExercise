class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int temp = INT_MIN, min, swap;
        for (int j = nums.size()-1; j > -1; j--) {
            if (nums[j] < temp) {
                //cout << "decreasing at " << j << endl;
                min = INT_MAX;
                for (int k = j+1; k < nums.size(); k++) {
                    if (nums[k] > nums[j] && nums[k] < min) {
                        min = nums[k];
                        swap = k;
                    }
                }
                temp = nums[swap];
                nums[swap] = nums[j];
                nums[j] = temp;
                sort(nums.begin()+j+1, nums.end());
                //sort(nums.begin()+j, nums.end(),greater<int>());
                return;
            }
            temp = nums[j];
        }
        reverse(nums.begin(), nums.end());

        return;
    }
};
//the fatest method 8ms which is faster twice than mine
// https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int k = -1, l = -1;
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            reverse(nums.begin(), nums.end());
        }
        else {
            for (int i = len - 1; i > k; i--) {
                if (nums[k] < nums[i]) {
                    l = i;
                    break;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
