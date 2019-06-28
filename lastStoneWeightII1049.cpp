/*
 *We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose any two rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the smallest possible weight of this stone (the weight is 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0 so the array converts to [1] then that's the optimal value.
[1,2,3,4,5,6,7,8,2,2,3,4,5,6,7,8,3,2,3,4,5,6,7,8,4,2,3,4,5,6,8,7] 
[35,33,30,25,19,11,53,40,36,10,31,23,26,13,14,18,33,22,16,22,16,28,16,72,25,23,19]
[58,60,49,53,22,6,21,15,39,63,47,7,26,24,54,59,69,60,19,39,28,47,25,62,15,25,62]
Note:

1 <= stones.length <= 30
1 <= stones[i] <= 100

   Hide Hint 1
Think of the final answer as a sum of weights with + or - sign symbols infront of each weight. Actually, all sums with 1 of each sign symbol are possible.
   Hide Hint 2
Use dynamic programming: for every possible sum with N stones, those sums +x or -x is possible with N+1 stones, where x is the value of the newest stone. (This overcounts sums that are all positive or all negative, but those don't matter.)
 *
 */
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //cout << stones.size() <<" , " << stones[15];
       vector<int> num;
        int temp, ans = INT_MAX;
        num.emplace_back(stones[0]);
        for (int i = 1; i < stones.size(); ++i) {
            vector<int> next;
            while (!num.empty()) {
                next.emplace_back(num.back()+stones[i]);
                next.emplace_back(num.back()-stones[i]);
                num.pop_back();
            }
            num = next;
        }
        for (int i:num) ans = min(ans, abs(i));
        return ans;
    }
};
/*the fatest method
 *Intuition
Same problem as:
Divide all numbers into two groups,
what is the minimum difference between the sum of two groups.
Now it's a easy classic knapsack problem.


Brief Prove
All cases of "cancellation of rocks" can be expressed by two knapsacks.
And the last stone value equals to the difference of these two knapsacks
It needs to be noticed that the opposite proposition is wrong.

Solution 1
Explanation:
Very classic knapsack problem solved by DP.
In this solution, I use dp to record the achievable sum of the smaller group.
dp[x] = 1 means the sum x is possible.


Time Complexity:
O(NS) time,
O(S) space, where S = sum(A).
 *
 *
 */
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        bitset<1501> dp = {1};
        int sumA = 0, res = 100;
        for (int a : stones) {
            sumA += a;
            for (int i = sumA; i >= a; --i)
                dp[i] = dp[i] + dp[i - a];
        }
        for (int i = sumA / 2; i > 0; --i)
            if (dp[i]) return sumA - i - i;
        return 0;  
    }
};

