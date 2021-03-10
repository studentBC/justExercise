class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int>num(arr.begin(), arr.end());
        for (int i = 1; i <= 2000; i++) {
            if (!num.count(i)) k--;
            if (!k) return i;
        }
        return 2001;
    }
};
//the fatest solution
class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        int n = A.size();
        int lo = 0, hi = n - 1;
        while (lo + 1 < hi) {
            int m = (lo + hi) / 2;
            int miss = A[m] - (m + 1);
            
            if (miss < k) lo = m;       // 注意这里！ < k 说明左边不够
            else hi = m;                // miss >= k的情况，=也向做移动
        }
        int missH = A[hi] - (hi + 1);
        int missL = A[lo] - (lo + 1);
        if (missH < k) return A[hi] + (k - missH);
        if (missL < k) return A[lo] + (k - missL);
        return k;
    }
};
