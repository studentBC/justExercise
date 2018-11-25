static int speedUp = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count=0;
        while(m!=n)
        {
            m/=2;
            n/=2;
            count++;
        }
        return m<<count;
    }
};
//my method
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bit = 1, ans = 0;
        for (int i = 31; i > -1; i--) {
            bit = 1;
            for (long j = m; j <= n; j++) {
                bit = j>>i&1&bit;
                if (bit == 0)break;
            }
            //cout << bit << " , ";
            if (bit!=0) {
                ans+=pow(2,i);
            }
        }
        return ans;
    }
};
