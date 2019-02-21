class Solution {
public:
	void combine (int start, vector<int>& nums, vector<int>& temp, int& ans) {
		if (temp.size() == 3) {
			if (temp[0]+temp[1] > temp[2] && temp[0]+temp[2] > temp[1] && temp[1]+temp[2] > temp[0]) ans++;
		} else {
			for (int i = start; i < nums.size(); i++) {
				temp.push_back(nums[i]);
				combine(i+1, nums, temp, ans);
				temp.pop_back();
			}
		}
	}
    int triangleNumber(vector<int>& nums) {
		vector<int>temp;
		int ans = 0;
 		combine (0,nums,temp,ans);
		return ans;
    }
};
//the fatest mthod
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = n - 1; i >= 2; --i) {
            int c = nums[i];
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] <= c) {
                    ++left;
                }
                else {
                    count += right - left;
                    --right;
                }
            }
        }
        
        return count;
    }
};
