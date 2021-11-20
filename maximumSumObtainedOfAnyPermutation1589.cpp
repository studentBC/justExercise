class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int len = nums.size();
        long long sum = 0;
        int mod = 1e9+7;
        vector<long long>count(len, 0);
        for (int i = 0; i < requests.size(); i++) {
            count[requests[i][0]]++;
            if (requests[i][1]+1 < len) count[requests[i][1]+1]--;
        }
        for (int i = 1; i < len; i++) count[i] += count[i-1];
        //cout <<"here";
        sort(count.begin(), count.end(), greater<long long>());
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < len; i++) {
            sum+= (count[i]*nums[i])%mod;
            sum%=mod;
        }
        return sum;
    }
};
