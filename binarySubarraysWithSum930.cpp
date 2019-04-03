class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int count = 0, sum = 0;
        vector<int>acc;
        for (int i = 0; i < A.size(); i++) {
            sum+=A[i];
			if (sum == S) count++;
            acc.push_back (sum);
        }
        for (int i = 0; i < acc.size(); i++) {
            for (int j = i; j < acc.size(); j++) {
                if (acc[j]-acc[i] == S) {
                    count++;
                } else if (acc[j]-acc[i] > S) {
                    break;
                }
            }
        }
		if (S == 0) return count-A.size();
        return count;
    }
};
//28 ms method
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        vector<int> sum(n + 1, 0), f(n + 1, 0);
        for (int i = 0; i < n; i ++ ) sum[i + 1] = sum[i] + A[i];
        f[0] = 1;
        int res = 0;
        for (int i = 1; i <= n ;  i ++) {
            if (sum[i] - S >= 0) res += f[sum[i] - S];
            f[sum[i]] ++ ;
        }
        return res; 
    } 
};
