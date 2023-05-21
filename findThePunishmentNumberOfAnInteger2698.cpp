class Solution {
public:
    void go (int start, int target, vector<int>& nums, bool& ans) {
        if (ans || target < 0) return;
        else if (target == 0 && start == nums.size()) {
            ans = true;
            return;
        }
        int sum = 0;
        for (int i = start; i < nums.size(); i++) {
            sum*=10;
            sum+=nums[i];
            go (i+1, target-sum, nums, ans);
            
        }
    }
    bool valid (int num) {
        int target = num*num;
        vector<int>nums;
        //int tmp = target;
        while (target) {
            nums.push_back(target%10);
            target/=10;
        }
        reverse(nums.begin(), nums.end());
        bool ans = false;
        go (0, num, nums, ans);
        return ans;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (valid(i)) {
                ans+=i*i;
            }
        }
        return ans;
    }
};
