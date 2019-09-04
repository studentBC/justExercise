class Solution {
public:
	int go (int n, int k) {
		if (n == 0 && k == 0) return 0;
		if (k%2) {
			return !go (n-1, (k-1)/2);
		} else {
			return go (n-1, k/2);
		}
	}
    int kthGrammar(int N, int K) {
		return go (N-1, K-1);
    }
};
