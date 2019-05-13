// Let k be 2
// Focus on "growth" of the pattern
// Define A' to be a partition over A that gives max sum

// #0
// A = {1}
// A'= {1} => 1

// #1
// A = {1, 2}
// A'= {1}{2} => 1 + 2 => 3 X
// A'= {1, 2} => {2, 2} => 4 AC
    
// #2
// A = {1, 2, 9}
// A'= {1, 2}{9} => {2, 2}{9} => 4 + 9 => 13 X
// A'= {1}{2, 9} => {1}{9, 9} => 1 + 18 => 19 AC

// #3
// A = {1, 2, 9, 30}
// A'= {1}{2, 9}{30} => {1}{9, 9}{30} => 19 + 30 => 49 X
// A'= {1, 2}{9, 30} => {2, 2}{30, 30} => 4 + 60 => 64 AC

// Now, label each instance. Use F1() to represent how A is partitioned and use F2() to represent
// the AC value of that partition. F2() is the dp relation we are looking for.

// #4
// A = {1, 2, 9, 30, 5}
// A'= F1(#3){5} => F2(#3) + 5 => 69 X
// A'= F1(#2){30, 5} => F2(#2) + 30 + 30 => 79 AC
// => F2(#4) = 79
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int>sum(A.size());
		int big = 0;
        for (int i = 0; i < A.size(); i++) {
			big = 0;
			for (int j = 1; j <= K && i-j > -2; j++) {
				big = max (big, A[i-j+1]);
				if (i >= j) {
					sum[i] = max (sum[i], sum[i-j]+big*j);
				} else {
					sum[i] = max (sum[i], big*j);
				}
			}
		}
		return sum.back();
    }
};
//the fatest method
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> a(n + 1, 0);
        for (int i = 0; i < n; ++i){
            int maxi = 0;
            for (int j = i; j < i + K && j < n; ++j){
                maxi = max(maxi, A[j]);
                a[j + 1] = max(a[j + 1], a[i] + (j - i + 1) * maxi);
                // cout<<j + 1 << "  " << a[j + 1] << endl;
            }
        }
        return a[n];
    }
};

