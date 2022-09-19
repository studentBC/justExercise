class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int cur, ans = 0, p, n, pos = 0, neg = 0;
        if (nums[0] < 0) {
            cur = -1;
            neg = 1;
        } else if (nums[0] == 0) {
            cur = pos = neg = 0;
        } else {
            cur = ans = pos = 1;
        }
        for (int i = 1; i < nums.size(); i++) {
            p = pos;
            n = neg;
            if (nums[i] == 0) {
                pos = neg = 0;
            } else if (nums[i] < 0) {
                if (n) pos = n+1;
                else pos = 0;
                if (p) neg = p+1;
                else neg = 1;
            } else {
                pos = p+1;
                if (n) neg = n+1;
                else neg = 0;
            }
            ans = max(ans, pos);
        }
        
        return ans;
    } 
};
