/*
 * I want to try to explain why we choose median instead of average(the proof is from smaller size of array to a larger size of array)
Let's say the sorted array is nums and nums.length == 2, then how do we choose value C where C is the final element value? (I will assume the array is sorted in the below context and the size of the array is n which is relatively large)

The range of C is [min, max] where min and max are the minimum and maximum value in the array, proof:
1.1. If C is equal to min, we denote the total move as m1. then
if C is smaller than min, then the total move must be greater than m1 because all the elements in the array have to go smaller than min to reach C which results in the total move to be: m1 + k
1.2 If C is equal to max, we denote the total move as m2, then
if C is greater than max, then the total move must be greater than m2 because all the elements in the array have to go greater than max to reach C which results in the total move to be: m2 + k
So we know that C is an integer between min and max
C is the median if array size is odd, C is the any number in [left median, right median] if size is even(I say left/right median here because C is eventually an integer, but it may happen that the median is not integer) or
you can simply say C is the median of the array which looks incorrect but give the right result(wrong assumption but correct result also happens for #122 Best Time to Buy and Sell Stock II if you did it before), proof:
Let's start from C is min, the total move is m1 which is described at proof1, then
2.1 If C becomes to min + 1 and C <= nums[1], is it better or worse?
Better, since for nums[0], it adds 1 more move to m1, but for the rest n - 1 elements, they decrease m1 n - 1 moves, so total move = m1 +1 - (n - 1) = m1 + 2 - n. So when n >= 2, we make the total move smaller.
2.2 If C becomes to min + 2 and C <= nums[1], is it better or worse?
Better. Like above, the total move becomes to (m1 + 2 - n) + (1 - (n - 1)) = (m1 + 2 - n) + (2 - n) which makes the total move smaller when n >= 2
2.3 If C becomes to min + 3 and C <= nums[1], is it better or worse?
Better. Like above, the total move becomes to (m1 + 2 - n + 2 - n) + (1 - (n - 1)) = (m1 + 2 - n) + (2 - n) + (2 - n) which makes the total move smaller when n >= 2
So we know that for C, from nums[0] to nums[1], we are always getting better result.
Likewise, if C from nums[1] to nums[2], total move = m1 + 2 - (n - 2) = m1 + 4 - n, => m1 + 4 - n + 4 - n => m1 + 4 - n + 4 - n + ..., so we get better result for n >= 4
Likewise, if C from nums[2] to nums[3], total move = m1 + 3 - (n - 3) = m1 + 6 - n, => m1 + 6 - n + 6 - n => m1 + 6 - n + 6 - n + ..., so we get better result for n >= 6
We can represent the total move as m1 + left- right where left is number of elements smaller than C, right is the number of elements greater than C. If left < right, then increasing C will always gives us better result. So if left == right, we get the smallest move, so we can choose C as the median.
Median is just one of the choice, C is not determinate. For example, [1, 3, 5, 8], C can be 3, 4, 5. All work.

*/
class Solution {
public: 
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		int ans = 0, i = 0, j = nums.size()-1;
        while (i < j) {
			ans+=(nums[j]-nums[i]);
        }
        return ans;
    }
};

