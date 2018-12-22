class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }
        vector<int>profit(nums);
        vector<bool>head(nums.size(), false);
        head[0] = true;
        int jone , jtwo;
        //start from position 1
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) {
                profit[1] = nums[0];
                head[1] = true;
            }
        }
        for (int i = 2; i < nums.size() -1; i++) {
            jone = profit[i-2]+nums[i];
            if (i>=3) jtwo = profit[i-3]+nums[i];
            if (jone > jtwo) {
                profit[i] = jone;
                if (head[i-2]) head[i] = true;
            } else {
                profit[i] = jtwo;
                if (head[i-3]) head[i] = true;
            }
        }
        for (int i = nums.size()-3; i > -1; i--) {
            if (!head[i]) {
                profit[profit.size()-1] = nums[nums.size()-1] + profit[i];
                break;
            }
        }
        int maxone = 0;
        for (int i = 0; i < profit.size(); i++) {
            if (maxone < profit[i]) maxone = profit[i];
        }
        cout << maxone << endl;
        //start from end
        for (int i = 0; i < nums.size(); i++) {
            head[i] = false;
            profit[i] = nums[i];
        }
        head[head.size()-1] = true;
        if (nums[nums.size()-1] > nums[nums.size()-2]) {
            profit[nums.size()-2] = profit[nums.size()-1];
            head[nums.size()-2] = true;
        }
        int start = nums.size()-3;
        jone = jtwo = 0;
        for (int i = start; i > 0; i--) {
            jone = profit[i+2]+nums[i];
            if (i<start) jtwo = profit[i+3]+nums[i];
            if (jone > jtwo) {
                profit[i] = jone;
                if (head[i+2]) head[i] = true;
            } else {
                profit[i] = jtwo;
                if (head[i+3]) head[i] = true;
            }
        }
        for (int i = 2; i < nums.size(); i++) {
            if (!head[i]) {
                profit[0] = nums[0] + profit[i];
                break;
            }
        }
        int maxend = 0;
        for (int i = 0; i < profit.size(); i++) {
            if (maxend < profit[i]) maxend = profit[i];
        }
        cout << maxend << endl;
        if (maxone > maxend) {
            return maxone;
        } else {
            return maxend;
        }
    }
};
//the fatest mtehod
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        if(size == 1)
            return nums[0];
        int pre = 0, cur = 0;
        for(int i = 0; i < size-1; i++)
        {
            int temp = pre;
            pre = cur;
            cur = max(pre, temp + nums[i]);
        }
        int pre1 = 0, cur1 = 0;
        for(int i = 1; i < size; i++)
        {
            int temp = pre1;
            pre1= cur1;
            cur1 = max(pre1, temp + nums[i]);
        }
        return max(cur, cur1);
    }
};
