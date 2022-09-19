/*
 Algorithm

In order to find the number of derangements for nn numbers, firstly we can consider the the original array to be [1,2,3,...,n]. Now, in order to generate the derangements of this array, assume that firstly, we move the number 1 from its original position and place at the place of the number ii. But, now, this i th position can be chosen in n-1n−1 ways. Now, for placing the number ii we have got two options:

We place i at the place of 1: By doing this, the problem of finding the derangements reduces to finding the derangements of the remaining n−2 numbers, since we've got n-2 numbers and n-2 places, such that every number can't be placed at exactly one position.

We don't place i at the place of 1: By doing this, the problem of finding the derangements reduces to finding the derangements for the n-1 elements(except 1). This is because, now we've got n-1 elements and these n-1 elements can't be placed at exactly one location(with i not being placed at the first position).

Derangement_Split

Based, on the above discussion, if d(n) represents the number of derangements for nn elements, it can be obtained as:

d(n)=(n−1)⋅[d(n−1)+d(n−2)]

This is a recursive equation and can thus, be solved easily by making use of a recursive function.

But, if we go with the above method, a lot of duplicate function calls wiil be made, with the same parameters being passed. This is because the same state can be reached through various paths in the recursive tree. In order to avoid these duplicate calls, we can store the result of a function call, once its made, into a memoization array. Thus, whenever the same function call is made again, we can directly return the result from this memoization array. This helps to prune the search space to a great extent.

Caution: The maximum recursion depth of this implementation is nn. So when nn is very large, it is possible to exceed the recursion limit or the memory limit. As such, the following code will not pass all test cases. Thus, in the following approaches we will discuss two improvements that can be applied to circumvent this issue.
 */
class Solution {
public:
    int findDerangement(int n) {
        vector<long long>dp(n+3);
        dp[0] = dp[1] = 0;
        dp[2] = 1;
        int mod = 1e9+7;
        long long ans = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
            dp[i]%=mod;
        }
        return dp[n];
    }
};
