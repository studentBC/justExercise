class Solution {
public:
    long long dp[1111][1<<11];
    long long mod = 1e9+7;
    vector<int>primes;
    long long getMask(long long num) {
        long long mask = 0;
        for (int i = 0; i < 10; i++) {
            int count = 0;
            while (num%primes[i] == 0) {
                count++;
                num/=primes[i];
            }
            if (count > 1) return -1;
            else if (count == 1) mask |= (1 <<(i+1));
        }
        return mask;
    }
    long long go(int index, long long mask, vector<int>& nums) {
        if (index >= nums.size()) return 1;
        if (dp[index][mask]!= -1) return dp[index][mask];
        long long m = getMask(nums[index]);
        long long ans = go(index+1, mask, nums);
        if ( (mask&m) == 0) {
            ans = (ans+go(index+1, m|mask, nums))%mod;
        }
        return dp[index][mask] = ans;
    }
    int squareFreeSubsets(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        return go(0, 1, nums)-1;
    }
};
