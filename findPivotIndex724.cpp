class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() == 0 or nums.size() == 2) return -1;
		int sum = 0, left, right;
		vector<int>acc(nums.size(),0);
		for (int i = 0; i < nums.size(); i++) {
			sum+=nums[i];
			acc[i] = sum;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (i == 0) {
				if (sum == acc[0]) return 0;
			} else {
				left = acc[i-1];
				right = sum - acc[i];
				if (left == right) return i;
			}
		}
		return -1;
    }
};
//16 ms method
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() == 0 or nums.size() == 2) return -1;
        
        int left_sum = 0;
        int right_sum = std::accumulate(nums.begin(), nums.end(), 0);
        
        for(int i = 0; i < nums.size(); ++i) {
            right_sum -= nums[i];
            if(i > 0) left_sum += nums[i - 1];
            if(right_sum == left_sum) return i;
        }
        
        return -1;
    }
};
