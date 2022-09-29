/*For every index i, we need the index j < i, such that dp[i] can be derived from dp[j] using a summation. Basically for any index i, j is the first index to the left of i where books[j] < books[i] - i + j. This index j is obtained using a monotonic stack.
*/
class Solution {
    public:
        long long sum (long long n) {
            if (n < 0) return 0;
            return (n*(n+1))/2;
        }
        long long maximumBooks(vector<int>& books) {
            vector<int>s;
            vector<long long>dp;
            long long ans = 0;
			// dp[i] represents max number of books that can be taken
			// between shelf 0 and shelf i (both inclusive)

			// use monotonic stack to populate dp array; for every index i,
			// find the nearest break point j < i such that books[i - j] <
			// books[i] - i + j

			// this becomes the restraining point for picking books as now
			// instead of picking (books[i] - i + j) books, we can only pick
			// books[i - j] books; so we will pick the maximum dp[j] books +
			// (books[i] + books[i] - 1 + books[i] - 2 + ... + books[i] - (i - j - 1))
            for (int i = 0; i < books.size(); i++) {
                while (!s.empty() && books[i]-i+s.back() <= books[s.back()]) s.pop_back();
                dp.push_back(s.empty()?0:dp[s.back()]);
				// pick dp[j] books and (books[i] + books[i] - 1 + ... + books[i] -
				// (i - j - 1)) books, where j is the current stack top; the latter
				// expression can be rewritten as a difference of two n-summations
                dp[i]+=sum(books[i]) - sum(books[i]-i+(s.empty()?-1:s.back()));
                ans = max(ans, dp[i]);
                s.push_back(i);
            }
            return ans;
        }
};
