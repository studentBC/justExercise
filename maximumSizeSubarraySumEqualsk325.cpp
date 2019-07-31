/*
given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
Follow Up:
Can you do it in O(n) time?
*/
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
		if (nums.size() == 0) return 0;
 		int acc[nums.size()] = {0};
		int sum = 0, ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum+=nums[i];
			acc[i] = sum;
			if (sum == k) ans = max(ans,i+1);
		}
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i+1; j < nums.size(); j++) {
				if (acc[j]-acc[i] == k) ans = max(ans, j-i);
			}
		}
		return ans;
    }
};
//the fatest method
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sum2idx;
        sum2idx[0] = -1;
        
        int sum = 0, n = nums.size(),result = 0;
        for(int i=0; i < n; i++)
        {
            sum += nums[i];
            if( sum2idx.count(sum-k) )
            {
                result = max(result, i- sum2idx[sum-k]);
                
            }
            
            if(sum2idx.count(sum) == 0)
                sum2idx[sum] = i;
        }
        
        return result;
    }
};

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
//concept
public int maxSubArrayLen(int[] nums, int k) {
    int sum = 0, max = 0;
    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    for (int i = 0; i < nums.length; i++) {
        sum = sum + nums[i];
        if (sum == k) max = i + 1;
        else if (map.containsKey(sum - k)) max = Math.max(max, i - map.get(sum - k));
        if (!map.containsKey(sum)) map.put(sum, i);
    }
    return max;
}
/*
The HashMap stores the sum of all elements before index i as key, and i as value. For each i, check not only the current sum but also (currentSum - previousSum) to see if there is any that equals k, and update max length.

PS: An "else" is added. Thanks to beckychiu1988 for comment.
*/

