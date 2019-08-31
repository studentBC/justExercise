class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        //sort (A.begin(), A.end());
        bool used[400000] = {false};
        int end = A.size()-1, ans = 0;
        for (int i = 0; i <= end; i++) {
            //cout << A[i] << " , ";
            if (used[A[i]]) {
                for (int j = A[i]+1; j < 400000; j++) {
                    if (!used[j]) {
                        //cout << i << " , ";
                        //A[i+1] = i;
                        used[j] = true;
                        ans+=(j-A[i]);
                        break;
                    }
                }
            } else {
                used[A[i]] = true;
            }
        }
        return ans;
    }
};
//the fatest method
#define M 40000

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        const int N = A.size();
        int v[M];
        memset(v, 0, sizeof(v));
        int K = 0;
        for (int i = 0; i < N; ++i) {
            ++v[A[i]];
            if (A[i] > K) {
                K = A[i];
            }
        }
        int l = -1, r = 0;
        for (int i = 0; i <= K; ++i) {
            if (v[i] > 0) {
                if (i <= l) {
                    int d = l + 1 - i;
                    r += v[i] * (d + d + v[i] - 1) / 2;
                    l = i + d + v[i] - 1;
                } else {
                    r += v[i] * (v[i] - 1) / 2;
                    l = i + v[i] - 1;
                }
            }
        }
        return r;
    }
};

