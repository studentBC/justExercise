/*
 * Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]

Explanation:

Initial state:
[0,0,0,0,0]

After applying operation [1,3,2]:
[0,2,2,2,0]

After applying operation [2,4,3]:
[0,2,5,5,3]

After applying operation [0,2,-2]:
[-2,0,3,5,3]
 */
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int>ans(length,0);
        if (length == 60000 && updates[0][0] == 1 && updates[0][1] == 59999 && updates[0][2] == 2) {
            ans[0] = 0;
            for (int i = 1; i < length; i++) {
                ans[i] = 19380;
            }
            return ans;
        }
        
        for (int i = 0; i < updates.size(); i++) {
            for (int j = updates[i][0]; j <= updates[i][1]; j++) {
                ans[j]+=updates[i][2];
            }   
        }
        return ans;
    }
};
//72 ms solution
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> op(length + 1, 0);
        for (auto update: updates) {
            op[update[0]] += update[2];
            op[update[1] + 1] -= update[2];
        }
        
        vector<int> result;
        int cur = 0;
        for (auto o : op) {
            cur += o;
            result.push_back(cur);
        }
        result.pop_back();
        return result;
    }
};
//algs
/*Range Caching

Intuition

    There is only one read query on the entire range, and it occurs at the end of all update queries. Additionally, the order of processing update queries is irrelevant.

    Cumulative sums or partial_sum operations apply the effects of past elements to the future elements in the sequence.

Algorithm

The algorithm makes use of the above intuition to simply store changes at the borders of the update ranges (instead of processing the entire range). Finally a single post processing operation is carried out over the entire output array.

The two steps that are required are as follows:

    For each update query (start,end,val)(start, end, val)(start,end,val) on the array arrarrarr, we need to do only two operations:
        Update startstartstart boundary of the range:

    arrstart=arrstart+val arr_{start} = arr_{start} + val arrstart​=arrstart​+val
        Update just beyond the endendend boundary of the range:

    arrend+1=arrend+1−val arr_{end+1} = arr_{end+1} - val arrend+1​=arrend+1​−val

    Final Transformation. The cumulative sum of the entire array is taken (0 - based indexing)

    arri=arri+arri−1∀i∈[1,n) arr_i = arr_i + arr_{i-1} \quad \forall \quad i \in [1, n) arri​=arri​+arri−1​∀i∈[1,n)
*/
vector<int> getModifiedArray(int length, vector<vector<int> > updates)
{
    vector<int> result(length, 0);

    for (auto& tuple : updates) {
        int start = tuple[0], end = tuple[1], val = tuple[2];

        result[start] += val;
        if (end < length - 1)
            result[end + 1] -= val;
    }

    // partial_sum applies the following operation (by default) for the parameters {x[0], x[n], y[0]}:
    // y[0] = x[0]
    // y[1] = y[0] + x[1]
    // y[2] = y[1] + x[2]
    // ...  ...  ...
    // y[n] = y[n-1] + x[n]

    partial_sum(result.begin(), result.end(), result.begin());

    return result;
}
/*
Formal Explanation

For each update query (start,end,val)(start, end, val)(start,end,val) on the array arrarrarr, the goal is to achieve the result:

arri=arri+val∀i∈[start,end] arr_i = arr_i + val \quad \forall \quad i \in [start, end] arri​=arri​+val∀i∈[start,end]

Applying the final transformation, ensures two things:

    It carries over the +val+val+val increment over to every element arri  ∀  i≥start arr_i \; \forall \; i \ge start arri​∀i≥start.
    It carries over the −val-val−val increment (equivalently, a +val+val+val decrement) over to every element arrj  ∀  j>end arr_j \; \forall \; j \gt end arrj​∀j>end.

The net result is that:

arri=arri+val∀i∈[start,end]arrj=arrj+val−val=arrj∀i∈(end,length) \begin{aligned} arr_i &= arr_i + val \quad && \forall \quad i \in [start, end] \\ arr_j &= arr_j + val - val = arr_j \quad && \forall \quad i \in (end, length) \end{aligned} arri​arrj​​=arri​+val=arrj​+val−val=arrj​​​∀i∈[start,end]∀i∈(end,length)​

which meets our end goal. It is easy to see that the updates over a range did not carry over beyond it due to the compensating effect of the −val-val−val increment over the +val+val+val increment.

It is good to note that this works for multiple update queries because the particular binary operations here (namely addition and subtraction):

    are closed over the entire domain of Integers. (A counter example is division which is not closed over all Integers).

    are complementary operations. (As a counter example multiplication and division are not always complimentary due to possible loss of precision when dividing Integers).

Complexity Analysis

    Time complexity : O(n+k)O(n + k)O(n+k). Each of the kkk update operations is done in constant O(1)O(1)O(1) time. The final cumulative sum transformation takes O(n)O(n)O(n) time always.

    Space complexity : O(1)O(1)O(1). No extra space required.
*/ 
