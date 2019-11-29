class Solution {
public:
	int atmost (vector<int>& A, int K) {
		int left = 0, ans = 0;
		unordered_map<int,int>count;
		for (int i = 0; i < A.size(); i++) {
			if (!count[A[i]]) {
				K--;
			}
			count[A[i]]++;
			while (K < 0) {
				count[A[left]]--;
				if (!count[A[left]]) K++;
				left++;
			}
			ans+= i-left+1;
		}
		return ans;
	}
    int subarraysWithKDistinct(vector<int>& A, int K) {
 		return atmost(A, K)-atmost(A, K-1);
    }
};
//the fatest solution
class Solution {
public:
    int subarraysWithKDistinct(vector<int> &a, int k) {
        const int n = a.size();
        
        int subarr_cnt = 0;
        vector<int> inner_freq(n + 1), outer_freq(n + 1);
        int inner_r = 0, outer_r = 0, inner_uniq_cnt = 0, outer_uniq_cnt = 0;
        
        // Invariant: inner_r points to the element right after we reach
        // uniq_cnt == k and outer_r points to the element where we would reach
        // uniq_cnt == k + 1
        for (int l = 0; l < n; l++) {
            // Re-adjust inner end of window
            while (inner_r < n && inner_uniq_cnt < k) {
                if (inner_freq[a[inner_r]] == 0) {
                    inner_uniq_cnt++;
                }
                inner_freq[a[inner_r]]++;
                inner_r++;
            }
            
            // Re-adjust outer end of window
            while (outer_r < n && (outer_uniq_cnt < k || outer_freq[a[outer_r]] != 0)) {
                if (outer_freq[a[outer_r]] == 0) {
                    outer_uniq_cnt++;
                }
                outer_freq[a[outer_r]]++;
                outer_r++;
            }
            
            // Count range of valid right ends
            if (inner_uniq_cnt == k && outer_uniq_cnt == k) {
                subarr_cnt += outer_r - inner_r + 1;
            }
            
            // Remove current element from window
            inner_freq[a[l]]--;
            if (inner_freq[a[l]] == 0) {
                inner_uniq_cnt--;
            }
            outer_freq[a[l]]--;
            if (outer_freq[a[l]] == 0) {
                outer_uniq_cnt--;
            }
        }
        return subarr_cnt;
    }
};
