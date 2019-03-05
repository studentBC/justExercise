class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        nums.push_back(INT_MAX);
        vector<int>id;
        vector<int>amount;
        int prev = nums[0] , count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (prev!=nums[i]) {
                id.push_back(prev);
                amount.push_back(count);
                //cout << prev << " , " << count << endl;
                count = 1;
            } else {
                count++;
            }
            prev = nums[i];
        }
        vector<int>sum(id.size()+1);
        sum[0] = 0;
        sum[1] = id[0]*amount[0];
        int now;
        for (int i = 1; i < id.size(); i++) {
            if (id[i-1]+1 == id[i]) {
                now = id[i]*amount[i]+sum[i-1];
                sum[i+1] = (now > sum[i])?now:sum[i];
            } else {
                sum[i+1] = sum[i]+id[i]*amount[i];
            }   
            //cout << sum[i+1] << " , ";
        }
        return sum[sum.size()-1];
    }
};

