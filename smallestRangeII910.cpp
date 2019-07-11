/*
 * Intuition:

For each integer A[i],
we may choose either x = -K or x = K.

If we add K to all B[i], the result won't change.

It's the same as:
For each integer A[i], we may choose either x = 0 or x = 2 * K.

Explanation:

We sort the A first, and we choose to add x = 0 to all A[i].
Now we have res = A[n - 1] - A[0].
Starting from the smallest of A, we add 2 * K to A[i],
hoping this process will reduce the difference.

Update the new mx = max(mx, A[i] + 2 * K)
Update the new mn = min(A[i + 1], A[0] + 2 * K)
Update the res = min(res, mx - mn)
Extending Reading:

I notice that no other posts help me explain this part,
So I decided to complete it myself.

Q: Do we have to sort the list?
A: In general cases, Yes. and this can be easily proved.

For example A = [0,1,4,5,6,7,8,9], K = 5
result = 2 * K - max(gap between numbers) = 2 * 5 - (4 - 1) = 7

To get the gap of consecutive numbers (in sorted order),
I don't have a better idea than sortting.


Q: If we add 2*K to A[i], why do we need to add 2*K to A[0] ~ A[i - 1]?
A: Yes we need to keep the array rotated sorted.

If we add 2*K to any A[i], now the maximum will be at least A[i] + 2*K
A[0] is the minimum and A[0] + 2K won't be bigger than A[i] + 2*K.

For example A = [0,1,4,5,6,7,8,9], K = 5
If we add K * 2 = 10 to 5, then we have [0,1,4,15,6,7,8,9],
we should also add 10 to 0,1 and 4.

In other words, if we add any A[i],
we should do the same thing to the all smaller numbers,
and keep the array rotated sorted.


Q: Except the general cases, do we any corner case?
A: Yes, we have.
if max(A) - min(A) >= 4 * K, return max(A) - min(A) - 2 * K
if max(A) - min(A) <= K, return max(A) - min(A)
Otherwise, we have to sort.


Q: Can we optimise this O(NlogN) solution?
A: No.

To be easier understood, I sort the whole list here.
But we don't have to.
We can only take and sort he number between [max(A) - 2 * K, min(A) + 2 * K]

This will help improve the complexity a lot.
In 30 of 68 total cases, we solve the problem in O(N).
In ther rest cases, we solve in O(KlogK) where K <= N.
 */
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
		sort(A.begin(),A.end());
		int ans = A.back()-A.front(), big = A.back(), small = A[0];
		for (int i = 0; i < A.size()-1; ++i) {
			small = min(A[0]+2*K, A[i+1]);
			big = max(big, A[i]+2*K);
			ans = min(ans, big-small);
		}
		return ans;
    }
};
