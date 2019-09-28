/*
The answer is between maximum value of input array numbers and sum of those numbers.
Use binary search to approach the correct answer. We have l = max number of array; r = sum of all numbers in the array;Every time we do mid = (l + r) / 2;
Use greedy to narrow down left and right boundaries in binary search.
3.1 Cut the array from left.
3.2 Try our best to make sure that the sum of numbers between each two cuts (inclusive) is large enough but still less than mid.
3.3 We'll end up with two results: either we can divide the array into more than m subarrays or we cannot.
If we can, it means that the mid value we pick is too small because we've already tried our best to make sure each part holds as many non-negative numbers as we can but we still have numbers left. So, it is impossible to cut the array into m parts and make sure each parts is no larger than mid. We should increase m. This leads to l = mid + 1;
If we can't, it is either we successfully divide the array into m parts and the sum of each part is less than mid, or we used up all numbers before we reach m. Both of them mean that we should lower mid because we need to find the minimum one. This leads to r = mid - 1;
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
 		long sum = 0, left, right, big = INT_MIN, mid;
		for (long i :nums) {
			sum+=i;
			big = max (i, big);
		}
		if (m == 1) return sum;
        left = big;right = sum;
		while (left <= right) {
			mid = (left+right)/2;
			if (check(mid, nums, m)) {
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		return left;
    }
	bool check (int target, vector<int>& nums, int m) {
		int count = 1;long total = 0;
		for (int i:nums) {
			total+=i;
			if (total > target) {
				total = i;
				count++;
				if (count > m) return false;
			}
		}
		return true;
	}
};
//the fatest solution
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long low=0, high=0;
        for(long c:nums){
            low=max(c, low);
            high+=c;
        }
        while(low<high){
            long mid=low+high>>1;
            long seg=1, sum=0;
            for(long c:nums){
                if(sum+c<=mid)
                    sum+=c;
                else{
                    seg++;
                    sum=c;
                }
            }
            if(seg>m)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};
