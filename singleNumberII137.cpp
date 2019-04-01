class Solution {
public:
    int singleNumber(vector<int>& nums) {
 		map<int,int>number;
		auto it = number.begin();
		for (int i = 0; i < nums.size(); i++) {
			it = number.find(nums[i]);
			if (it == number.end()) {
				number.insert(pair<int,int>(nums[i],1));
			} else {
				it->second++;
			}
		}
		for (it = number.begin(); it!=number.end(); it++) {
			if (it->second == 1) return it->first;
		}
		return 0;
    }
};
//the fatest method
class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int first = 0, second = 0;
        for (auto i : nums)
        {
            first = (first ^ i) & ~second;
            second = (second ^ i) & ~first;
        }
        return first;
    }
};
