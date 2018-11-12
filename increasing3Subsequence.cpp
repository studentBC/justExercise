class Solution {
public:
    bool find (vector<int>& nums, int start, int len) {
		for (int i = start+1; i < len; i++) {
			if (nums[i] > nums[start]) {
				for (int j = i+1; j < nums.size(); j++) {
					if (nums[j] > nums[i]) {
						return true;
					}
				}
			}
		}
        return false
    }

    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size()-2;
        for (int i = 0; i < len; i++) {
            if (find(nums, i, len)) return true;
        }
        return false;
    }
};
//the fatest method
static int x = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
                
        if (nums.size()<3)
            return false;
        
        int min_so_far=nums[0];
        int min2=nums[0];
        int min1=nums[0];
        int count=0;
        
        for (int i=1;i<nums.size();++i)
        {
            if (nums[i]<=min_so_far)
                min_so_far=nums[i];
            else if (count<1 || nums[i]<=min2)
            {
                min1 = min_so_far;
                min2 = nums[i];
                ++count;
            }
            else
                return true;            
        }
        
        return false;
    }
};
