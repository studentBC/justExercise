class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
 		int n = nums.size()/2, m, total;
		vector<int>ans;
		for (int i = 0; i < n; i++) {
			m = nums[2*i+1];
			total = nums[2*i];
			for (int j = 0; j < total; j++) ans.push_back(m);
		}
		return ans;
    }
};
