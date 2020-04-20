class Solution {
public:
    int findMinFibonacciNumbers(int k) {
 		vector<int>fib;
		fib.push_back(1);
		fib.push_back(1);
		while (fib.back() < k) {
			fib.push_back(fib.back()+fib[fib.size()-2]);
		}
		int ans = 0, last = fib.size()-1;
		while (k) {
			if (fib[last] > k) last--;
			else {
				k-=fib[last];
				ans++;
			}
		}
		return ans;
    }
};
