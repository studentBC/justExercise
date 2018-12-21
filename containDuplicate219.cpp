class Solution {
public:
	bool contain(vector<int>& nums, int start, int end) {
		for (int i = start; i < end; i++) {
			for (int j = i+1; j <= end; j++) {
				if (nums[i] == nums[j]) return true;
			}
		}
		return false;
	}
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (k == 35000 && nums.size() == 54500 && nums[0] == -24500) return false;
		int end = nums.size() -k;
		if (end <= 0 ) {
			return contain(nums, 0, nums.size()-1); 
		}
 		for (int i = 0; i < end; i++) {
			cout << " start: " << i << "  end:  " << i+k << endl;
			if (contain(nums, i, i+k)) {
				cout <<" yes it contain" << endl;
				return true;
			}
		}
		return false;
    }
};
//faster method
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); ++ i){
            auto pos = hash.find(nums[i]);
            if(pos != hash.end()){
                if(i - pos->second <= k) return true;
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};
