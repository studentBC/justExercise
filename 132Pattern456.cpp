class Solution {
public:
    bool find132pattern(vector<int>& nums) {
  		stack<int>num;
		int s3 = INT_MIN;
		for (int i = nums.size()-1; i > -1; i--) {
			if (nums[i] < s3) return true;
			while (!num.empty() && nums[i] > num.top()) {
				s3 = num.top();
				num.pop();
			}
			num.push(nums[i]);
		}
		return false;
    }
};
