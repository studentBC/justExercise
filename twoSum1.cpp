class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>number;
        for (int i = 0; i < nums.size(); i++) {
            number[nums[i]] = i;
        }
        vector<int>ans;
        for (int i = 0; i < nums.size(); i++) {
            //cout << i <<" , ";
            if (number[target-nums[i]] && i != number[target-nums[i]]) {
                ans.emplace_back(i);
                ans.emplace_back(number[target-nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int temp, i;
        unordered_map<int, int> num_map(nums.size());
        for (i = 0; i < nums.size(); ++i) {
            temp = target - nums[i];
            if (num_map.count(temp)) {
                break;
            }
            num_map.emplace(nums[i], i);
        }
        return vector<int>{num_map[temp], i};
    }
};
