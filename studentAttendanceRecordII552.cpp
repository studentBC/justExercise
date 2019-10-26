class Solution {
public:
    int checkRecord(int n) {
        vector<vector<long>>dp (n+1, vector<long>(4, 1));
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            sum = 0;
            for (int j = 0; j < 3; j++) {
                if (!j) {
                    if (i == 1) {
                        dp[i][j] = 1;
                    } else if (i == 2)  {
                        dp[i][j] = 2;
                    } else {
                        dp[i][j] = ((dp[i-1][0]+dp[i-2][0])%1000000007+dp[i-3][0])%1000000007;
                    }
                } else if (j == 1) {
                    if (i == 1) dp[i][j] = 1;
                    else {
                        dp[i][j] = dp[i-1][3];
                    }
                } else {
                    if (i == 1) {
                        dp[i][j] = 1;
                    } else if (i == 2) {
                        dp[i][j] = 3;
                    } else {
                        dp[i][j] = ((dp[i-1][0]+dp[i-1][1])%1000000007+ (dp[i-2][0] + dp[i-2][1]) %1000000007) % 1000000007;
                    }
                } 
                //cout << dp[i][j] <<" , ";
                sum+=dp[i][j];
                sum%=1000000007;
            }
            //cout << endl;
            dp[i][3] = sum;
        }
        return dp[n][3];
    }
};
//the fatest solution
typedef vector<long long> VI;
typedef vector<VI> VVI;
const long long MOD = 1000000007LL;

VVI mult(const VVI& a, const VVI& b) {
    VVI c(a.size(), VI(b[0].size(), 0));
    for (size_t i = 0; i < c.size(); i++) {
        for (size_t j = 0; j < c[0].size(); j++) {
            for (size_t k = 0; k < b.size(); k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

VVI power(int n) {
    VVI a(6, VI(6, 0));
    VVI b(6, VI(6, 0));
    for (int i = 0; i < 6; i++) {
        a[i][i] = 1;
    }
    vector<vector<int>> edges = { {0, 0}, {0, 1}, {0, 3}, {1, 0}, {1, 2}, {1, 3}, {2, 0}, {2, 3}, {3, 3}, {3, 4}, {4, 3}, {4, 5}, {5, 3} };
    for (auto edge : edges) {
        b[edge[1]][edge[0]] = 1;
    }
    while (n) {
        if (n & 1) a = mult(b, a);
        b = mult(b, b);
        n /= 2;
    }
    return a;
}
class Solution {
public:
    int checkRecord(int n) {
        auto a = power(n);
        long long r = 0LL;
        for (size_t i = 0; i < a.size(); i++) {
            r = (r + a[i][0]) % MOD;
        }
        return r;
    }
};
