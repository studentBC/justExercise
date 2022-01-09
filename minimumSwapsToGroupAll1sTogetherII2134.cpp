class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int one = 0, window = 0, len = nums.size(), x = 0;
        one = count(begin(nums), end(nums), 1);
        vector<int>num(len*2);
        for (int i = 0; i < len*2; i++) num[i] = nums[i%len];
        for (int i = 0; i < len*2; i++) {
                if (i >= one && num[i-one] == 1) x--;
                if (num[i] == 1) x++;
                window = max(x, window);
        }
        return one-window;
    }
};
