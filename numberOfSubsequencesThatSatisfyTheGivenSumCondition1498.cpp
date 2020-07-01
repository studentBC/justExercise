/*
Sort the array nums.
Use two pointers approach: Given an index i (choose it as the minimum in a subsequence) find the maximum j where j ≥ i and nums[i] +nums[j] ≤ target.
Count the number of subsequences.

Idea:

The number of elements we can include in the subsequence is dependent on the MINIMUM value that the subsequence contains
The smaller the minimum, the larger the maximum is allowed to be
Sort the input to seperate mins and maxes, the order of elements doesn't change the number of subseqences that satisfy the condition
Two pointer time:
For each minimum, which is on the left, count how many values to its right can be included into a subsequence with the minimum
We can count subsequences with this minimum by 2 ^ (count)
Since the left value (the minimum) is always in each of the subsequences, it is not added to count
Complexity

Time: O(nlogn)
Space: O(1)
*/
class Solution {
public: 
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, l = 0, r = nums.size()-1, mod = 1e9+7;
        vector<int>pow(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            pow[i] = pow[i-1]*2%mod;
        }
        while (l <= r) {
            if (nums[l]+nums[r] > target) r--;
            else {
                ans = (ans+pow[r-l])%mod;
                l++;
            }
        }
        return ans;
    }
};
// the fatest solution
class Solution {
public:
    typedef long long ll;
    int big;
    ll add(ll a, ll b) {
        ll c = a + b;
        return c%big;
    }
    ll mul(ll a, ll b) {
        ll c = a * b;
        return c%big;
    }
    int numSubseq(vector<int>& nums, int target) {
        big = 1000000007;
        int sz = nums.size();
        vector<int> dist(target+1, 0);
        vector<ll> twoPower(sz+1, 0); // twoPower[i] = 1 << i;
        twoPower[0] = 1;
        for (int i=1; i <= sz; ++i) {
            twoPower[i] = add(twoPower[i-1], twoPower[i-1]);
        }
        for (int i=0; i < sz; ++i) {
            int v = nums[i];
            if (v <= target)
                dist[v]++;
        }
        ll ans = 0;
        vector<ll> presum(target+1, 0);
        for (int i=1; i <= target; ++i) {
            int v = dist[i];
            presum[i] = presum[i-1] + v;
            if (v == 0)
                continue;
            ll cur;
            if ( (i+i) <= target) {
                cur = mul(twoPower[v]-1, twoPower[presum[i-1]]);
                //cout << "i=" << i << " v=" << v << " cur=" << cur << endl;
            } else {
                int mn = target - i;
                if (presum[mn] == 0) break;
                ll part1 = twoPower[presum[mn]] - 1;
                ll part2 = twoPower[presum[i-1] - presum[mn]];
                ll part3 = twoPower[v]-1;
                cur = mul(mul(part1, part2), part3);
                //cout << "i=" << i << " v=" << v << " cur=" << cur << " p1=" << part1 << " p2=" << part2 << " p3=" << part3 << endl;
            }
            ans = add(ans, cur);
            //cout << "i=" << i << " v=" << v << " ans=" << ans << endl;
        }
        return ans;
    }
};
