class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int>count;
        int ans = 0, product;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                product = nums[i] * nums[j];
                ans += count[product] * 8;
                count[product]++;
            }
        }
        return ans;
    }
};
