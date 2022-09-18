class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        vector<long long>sum;
        long long s = 0, ans = INT_MIN, front;
        sum.push_back(0);
        for (int i : nums) {
            s+=i;
            sum.push_back(s);
        }
        for (int i = 1; i < sum.size(); i++) {
            ans = max(ans, max(sum[i], sum.back()-sum[i-1]));
        }
        return ans;
    }
};
