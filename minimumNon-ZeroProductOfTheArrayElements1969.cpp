class Solution {
public:
    int mod = 1e9+7;
    long long fp(long long a, long long b) {
        long long p = 1;
        a %= mod;
        while(b) {
            if(b & 1) p *= a;
            a *= a;
            b = b >> 1;
            p %= mod;
            a %= mod;
        }
        return p % mod;
    }
    int minNonZeroProduct(int p) {
        long long end = 1;
        end<<=p;
        end--;
        long long count = end/2, ans = end;
        if (p == 1) return 1;
        else if (p == 2) return 6;
        else {
            end--;
            ans = fp(end, count)%mod*(ans%mod)%mod;
        }
        return ans;
    }
};
