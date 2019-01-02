class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string>ans;
		if (nums.size() == 0) return ans;
		string temp = to_string(nums[0]);
		int prev = nums[0],end = INT_MIN;
		nums.push_back(INT_MAX);
 		for (int i = 1; i < nums.size(); i++) {
			if (nums[i]-prev == 1) {
				end = nums[i];
			} else {
				if (end > stoi(temp)) {
					temp+="->";
					temp+=to_string(end);
				}
				ans.push_back(temp);
				temp = to_string(nums[i]);
			}
			prev = nums[i];
		}
		return ans;
    }
};
