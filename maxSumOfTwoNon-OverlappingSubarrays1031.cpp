class Solution {
public: 
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int>ls , ms; int ans = 0;
        int sum = 0 , end = A.size()-L;
        for (int j = 0; j < L; j++) {
            sum+=A[j];
        }
        ls.emplace_back(sum);
        for (int i = 1; i <= end; i++) {
            sum-=A[i-1];
            sum+=A[i+L-1];
            ls.emplace_back(sum);
        }
        sum = 0 , end = A.size()-M; 
        for (int j = 0; j < M; j++) {
            sum+=A[j];
        }
        ms.emplace_back(sum);
        for (int i = 1; i <= end; i++) {
            sum-=A[i-1];
            sum+=A[i+M-1];
            ms.emplace_back(sum);
        }
        for (int i = 0; i < ms.size(); i++) {
            for (int j = 0; j < ls.size(); ++j) {
                if (j+L < i+1 || i+M < j+1) {
                    sum = ms[i]+ls[j];
                    ans = max(sum, ans);
                }
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int helper(vector<int>& A, int L, int M) {
        int sz = A.size();
        vector<int> bestL(sz, -1); // best L ends at i
        int tot = 0;
        for (int i=0; i < L; ++i)
            tot += A[i];
        bestL[L-1] = tot;
        for (int i=L; i < sz; ++i) {
            int pre = A[i-L];
            tot = tot - pre + A[i];
            bestL[i] = max(tot, bestL[i-1]);
        }
        tot = 0;
        for (int i=sz-M; i < sz; ++i)
            tot += A[i];
        int ans = -1;
        int bestM = tot;
        for (int i=sz-M; i >=1; --i) {
            int cur = bestL[i-1] + bestM;
            ans = max(ans, cur);
            tot = tot + A[i-1] - A[i+M-1];
            bestM = max(bestM, tot);
        }
        return ans;
    }
    
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int ans1 = helper(A, L, M);
        int ans2 = helper(A, M, L);
        return max(ans1, ans2);
    }
};
