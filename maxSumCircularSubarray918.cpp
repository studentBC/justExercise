//my solution which will lead to TLE , we should study #53 first then do this problem
class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		vector<int>acc(A.size()*2);
		int sum = 0;
		int ans = INT_MIN;
		bool used = false;
		for (int i = 0, j = 0; i < acc.size(); ++i,j++) {
			if (j == A.size()) {
				j = 0;
				used = true;
			}
			sum+=A[j];
			if (!used) ans = max(sum, ans);
			acc[i] = sum;
		}
		for (int i = 1; i < A.size(); i++) {
			for (int j = 0; j < A.size(); ++j) {
				ans = max (ans, acc[i+j]-acc[i-1]);
			}
		}
		return ans;
	}
};
//the basic concept for #53
/*Analysis of this problem:
Apparently, this is a optimization problem, which can be usually solved by DP. So when it comes to DP, the first thing for us to figure out is the format of the sub problem(or the state of each sub problem). The format of the sub problem can be helpful when we are trying to come up with the recursive relation.

At first, I think the sub problem should look like: maxSubArray(int A[], int i, int j), which means the maxSubArray for A[i: j]. In this way, our goal is to figure out what maxSubArray(A, 0, A.length - 1) is. However, if we define the format of the sub problem in this way, it's hard to find the connection from the sub problem to the original problem(at least for me). In other words, I can't find a way to divided the original problem into the sub problems and use the solutions of the sub problems to somehow create the solution of the original one.

So I change the format of the sub problem into something like: maxSubArray(int A[], int i), which means the maxSubArray for A[0:i ] which must has A[i] as the end element. Note that now the sub problem's format is less flexible and less powerful than the previous one because there's a limitation that A[i] should be contained in that sequence and we have to keep track of each solution of the sub problem to update the global optimal value. However, now the connect between the sub problem & the original one becomes clearer:
maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i];
And here's the code

public int maxSubArray(int[] A) {
        int n = A.length;
        int[] dp = new int[n];//dp[i] means the maximum subarray ending with A[i];
        dp[0] = A[0];
        int max = dp[0];

        for(int i = 1; i < n; i++){
            dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            max = Math.max(max, dp[i]);
        }

        return max;
}


the max subarray circular sum equals to
max(the max subarray sum, the total sum - the min subarray sum)


Corner case

Just one to pay attention:
If all numbers are negative, maxSum = max(A) and minSum = sum(A).
In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty subarray.
According to the deacription, We need to return the max(A), instead of sum of am empty subarray.
So we return the maxSum to handle this corner case.

Complexity

One pass, time O(N)
No extra space, space O(1)

C++:

    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = -30000, curMax = 0, minSum = 30000, curMin = 0;
        for (int a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }

 */
class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		int sum = 0, maxsum = INT_MIN, minsum = INT_MAX, curmax = 0, curmin = 0;
		for (int i : A) {
			curmax = max (curmax+i, i);
			maxsum = max(maxsum, curmax);
			curmin = min(i,curmin+i);
			minsum = min(curmin, minsum);
			sum+=i;
		}
		
		if (maxsum > 0) return max (maxsum, sum-minsum);
		return maxsum;
	}
};

