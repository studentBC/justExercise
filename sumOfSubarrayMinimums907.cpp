/*
 * https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step
 *
 *
Before diving into the solution, we first introduce a very important stack type, which is called monotone stack .

What is monotonous increase stack?
Roughly speaking, the elements in the an monotonous increase stack keeps an increasing order.

The typical paradigm for monotonous increase stack:
for(int i = 0; i < A.size(); i++){
  while(!in_stk.empty() && in_stk.top() > A[i]){
    in_stk.pop();
  }
  in_stk.push(A[i]);
}
What can monotonous increase stack do?
(1) find the previous less element of each element in a vector with O(n) time:
What is the previous less element of an element?
For example:
[3, 7, 8, 4]
The previous less element of 7 is 3.
The previous less element of 8 is 7.
The previous less element of 4 is 3.
There is no previous less element for 3.
For simplicity of notation, we use abbreviation PLE to denote Previous Less Element.

C++ code (by slitghly modifying the paradigm):
Instead of directly pushing the element itself, here for simplicity, we push the index.
We do some record when the index is pushed into the stack.
// previous_less[i] = j means A[j] is the previous less element of A[i].
// previous_less[i] = -1 means there is no previous less element of A[i].
vector<int> previous_less(A.size(), -1);
for(int i = 0; i < A.size(); i++){
  while(!in_stk.empty() && A[in_stk.top()] > A[i]){
    in_stk.pop();
  }
  previous_less[i] = in_stk.empty()? -1: in_stk.top();
  in_stk.push(i);
}
(2) find the next less element of each element in a vector with O(n) time:
What is the next less element of an element?
For example:
[3, 7, 8, 4]
The next less element of 8 is 4.
The next less element of 7 is 4.
There is no next less element for 3 and 4.
For simplicity of notation, we use abbreviation NLE to denote Next Less Element.

C++ code (by slighly modifying the paradigm):
We do some record when the index is poped out from the stack.
// next_less[i] = j means A[j] is the next less element of A[i].
// next_less[i] = -1 means there is no next less element of A[i].
vector<int> previous_less(A.size(), -1);
for(int i = 0; i < A.size(); i++){
  while(!in_stk.empty() && A[in_stk.top()] > A[i]){
    auto x = in_stk.top(); in_stk.pop();
    next_less[x] = i;
  }
  in_stk.push(i);
}
*/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7, len = arr.size();
        long long ans = 0;
        vector<pair<int, int>>nle, ple;
        vector<long long>left(len), right(len);
        for (int i = 0; i < len; i++) {
            left[i] = i+1;
            right[i] = len-i;
        }
        
        for (int i = 0; i < len; i++) {
            while (!ple.empty() && ple.back().first > arr[i]) {
                ple.pop_back();
            }
            left[i] = ple.empty()?i+1:i-ple.back().second;
            ple.push_back({arr[i], i});
            while (!nle.empty() && nle.back().first > arr[i]) {
                right[nle.back().second] = i-nle.back().second;
                nle.pop_back();
            }
            nle.push_back({arr[i], i});
        }
        for (int i = 0; i < len; i++) {
            ans = (ans+arr[i]*left[i]*right[i])%mod;
        }
        return ans;
    }
};
