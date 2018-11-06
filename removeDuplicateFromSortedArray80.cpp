class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int len = nums.size() , prev = INT_MIN, count = 0;
		vector<int> temp;
 		for (int i = 0; i < len; i++) {
			if (prev!=nums[i]) {
				prev = nums[i];
				temp.push_back(nums[i]);
				count++;
			} else {
				if (i>1 && nums[i-1] == prev) {
					if (nums[i-2]!=prev) {
						temp.push_back(nums[i]);
						count++;
					}
				} else {
					temp.push_back(nums[i]);
					count++;
				}
			}
		}
		for (int i = 0; i < count; i++) {
			nums[i] = temp[i];
		}
		return count;
    }
};

//the fatest method
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 0;
        int now, times = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] != now){
                times = 0;
                now = nums[i];
            }
            times++;
            if(times <= 2) swap(nums[i], nums[result++]);
        }
        return result;
    }
};
