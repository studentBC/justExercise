class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		nums.push_back(INT_MAX);
 		vector<int>count(nums.size(),0);
		int max = 0, c = 0;
		for (int i = nums.size()-2; i > -1; i--) {
			max = 0;
			for (int j = i; j < nums.size(); j++) {
				if (nums[i] < nums[j]) {
					c = count[j]+1;
					if (c > max) max = c;
				}
			}
			count[i] = max;
		}
		max = 0;
		for (int i = 0; i < count.size(); i++) {
			if (count[i] > max) max = count;
		}
		return max;
    }
};
//the fatest method
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> res({nums[0]});
        for (int i = 1; i < nums.size(); ++i) {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end())
                res.push_back(nums[i]);
            else
                *it = nums[i];
        }
        
        return res.size();
    }
};
