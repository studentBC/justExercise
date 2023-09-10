/*
(prefix[j] - prefix[i])%modulo = k
prefix[j]%modulo - prefix[i]%modulo = k
prefix[i]%modulo = (prefix[j]%modulo - k)
This is easier to understand compared to other solution using
mp.find((prefix-k+mod)%mod)
*/
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long int ans = 0, len = nums.size(), sum = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i]%modulo == k) nums[i] = 1;
            else nums[i] = 0;
        }
        unordered_map<int, int>count;
        for (int i = 0; i < len; i++) {
            sum+=nums[i];
            int mod = sum%modulo;
            if (mod == k) ans++;
            int target = mod-k;
            if (target < 0) target+=modulo;
            ans+=count[target];
            count[mod]++;
        }
        return ans;
    }
};
