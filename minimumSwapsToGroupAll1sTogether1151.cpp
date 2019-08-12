/*
Given a binary array data, return the minimum number of swaps required to group all 1’s present in the array together in any place in the array.

Example 1:

Input: [1,0,1,0,1]
Output: 1
Explanation: 
There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.
Example 2:

Input: [0,0,0,1,0]
Output: 0
Explanation: 
Since there is only one 1 in the array, no swaps needed.
Example 3:

Input: [1,0,1,0,1,0,0,1,1,0,1]
Output: 3
Explanation: 
One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
 

Note:

1 <= data.length <= 10^5
0 <= data[i] <= 1
*/
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int width = 0, end, ans, zero = 0;
        for (int i:data) {
            if (i) width++;
        }
        end = data.size()-width;
        for (int i = 0; i < width; i++) {
            if (data[i] == 0) zero++;
        }
        ans = zero;
        for (int i = width, start = 0; i < data.size(); i++, start++) {
            if (data[i]) {
                if (data[start] == 0)zero--;
            } else {
                if (data[start])zero++;
            }
            ans = min (ans, zero);
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
  int minSwaps(vector<int>& data) {
    // How many 1 are in the array?
    const int ones = count(data.begin(), data.end(), 1);

    // Count 0 in a rolling window of size `ones`;
    // Remember the minimum in `result`.
    int zeros = 0;
    for (int i = 0; i < ones; ++i)
      if (data[i] == 0)
        ++zeros;
    int result = zeros;
    for (int i = ones; i < data.size(); ++i) {
      zeros += !data[i];
      zeros -= !data[i-ones];
      result = min(result, zeros);
    }
    return result;
  }
};

static auto const magic = []{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
