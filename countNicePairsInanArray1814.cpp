class Solution {
public:
    unordered_map<int,int>freq;
    int getInverse (int x) {
        int ans = 0, original = x;
        while (x)
        {
            int temp = ans * 10 + x % 10;
            if (temp / 10 != ans)
                return 0;
            ans = temp;
            x /= 10;
        }
        return original-ans;
    }
    int countNicePairs(vector<int>& nums) {
        int mod = 1e9+7;
        long long ans = 0, sum;
        vector<int>number;
        for (int i : nums) {
            freq[getInverse(i)]++;
        }
        for (auto& it: freq) {
            if (it.second > 1) {
                ans+=((long long)(it.second)*(long long)(it.second-1)/2);
                if (ans>=mod)ans%=mod;
            }
        }
        return ans;
    }
};
//88 ms solution
class Solution {
public:
    int rev(int x) {
        int r = 0;
        while(x) { r = r*10 + x%10; x /= 10; }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        map<int, int> diff;
        for (int n : nums) diff[n - rev(n)] += 1;
        long long r = 0;
        for (auto& it : diff) {
            r += it.second * (long long)(it.second-1) / 2;
        }
        return r % 1000000007;
    }
};
