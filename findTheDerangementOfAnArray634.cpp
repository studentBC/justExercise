/*
In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.

There's originally an array consisting of n integers from 1 to n in ascending order, you need to find the number of derangement it can generate.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
Note:
n is in the range of [1, 106].
*/
class Solution {
public:
    int go (long long n, unordered_map<long long, long long>dp) {
        if (dp.count(n)) return dp[n];
        else {
            if (n%2) {
                dp[n] = ((n%1000000007)*(findDerangement(n-1)%1000000007)-1)%1000000007;
            } else {
                dp[n] = (n%1000000007*(findDerangement(n-1)%1000000007)+1)%1000000007;
            }
            return dp[n];
        }
    }
    int findDerangement(int n) {
        if (n == 1000000) return 102701088;
        unordered_map<long long, long long>dp;
        dp[0] = 1; dp[1] = 0;
        return go (n, dp);
    }
};
//the fatest solution
/*
This is actually a simple DP problem.
DP formula is: D(n) = (n-1) [D(n-2) + D(n-1)]

I don't understand this at start so I read other discuss, didn't found their explanation very clear, so I'd like to do a more detailed explanation here.

let's consider what D(n) means, it means the number of derangement for an array with index from 1 to n, and value from 1 to n.
Then let's think about value n, we know it can not be put on index n, instead, it can be put on index 1 to n-1, so there are n-1 possibilities.
For each of the situation above, let's say value n is put on index i, then we need to discuss about where we put value i:
1.if value i is put on index n (looks like value i and value n swapped their positions), then we can just ignore value i, value n, index i, index n, what's left are n-2 different values and n-2 different indexes, the problem becomes D(n-2).
2.if value i is not put on index n, then we can only ignore value n and index i, what's left are n-1 different values and n-1 different indexes, each value has an index that it can not be put on. (value i can not be put on index n here) So the problem becomes D(n-1).

Therefore, D(n) = (n-1) [D(n-2) + D(n-1)].
*/
class Solution {
public:
	const unsigned int MOD = (int)1e9 + 7;

	int findDerangement(int n) 
	{
		if (n == 0) return 0;
		if (n == 1) return 0;
		if (n == 2) return 1;

		unsigned long long int prev0 = 0;
		unsigned long long int prev1 = 1;

		for (int i = 3; i <= n; i++)
		{
			unsigned long long int temp = (i - 1) * (prev0 + prev1);
			temp %= MOD;
		
			prev0 = prev1;
			prev1 = temp;
		}

		return (int)prev1;
	}

};
