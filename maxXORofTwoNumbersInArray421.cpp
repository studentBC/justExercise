class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
 		int max = INT_MIN , temp;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums.size(); j++) {
				temp = nums[i]^nums[j];
				if (max < temp) max = temp;
			}
		}
		return max;
    }
};
