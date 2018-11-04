class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
 		int len = nums.size();
		int temp[len];
		for (int i = 0; i < len; i++) {
			temp[i] = nums[i];
		}
		sort(nums.begin(),nums.end());
		int front = 1, back = 0;
		for (int i = 0; i < len; i++) {
			if (nums[i] != temp[i]) {
				front = i;
				break;
			}
		}
		for (int i = len-1; i > -1; i--) {
			if (nums[i] != temp[i]) {
				back = i;
				break;
			}
		}
		return back-front+1;
    }
};

// 12ms submit
static auto x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return nullptr;
}();

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int nums_size = nums.size();
        
        int transition[2] = {-1,0}; // -1 is needed to handle single element array
        int last_max = INT_MIN;
        int last_min = INT_MAX;
        
        // iterate forward to find the last transition        
        // in a sorted array, the current element is also the max in which case the corresponding transition index never gets updated
        // a transition is indicated by the last element that's not maximum
        for (int f = 0; f < nums_size; ++f) {
            if(last_max < nums[f])
                last_max = nums[f];
            else if (last_max != nums[f])
                transition[0] = f;
        }

        // iterate backward to find the first transition
        // in a sorted array, the current element is also the min in which case the corresponding transition index never gets updated
        // a transition is indicated by the first element that's not minimum
        for (int b = nums_size - 1; b >= 0; --b) {
            if(nums[b] <= last_min)
                last_min = nums[b];
            else if (nums[b] != last_min)
                transition[1] = b;
        }

        return transition[0] - transition[1] + 1;
    }
};
