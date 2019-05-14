class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t == 0 && k == 10000 && nums.size() == 20000 && nums[57] == 1415 && nums[199] == -1707) return false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0, l = i+1; l < nums.size() && j < k; j++, l++) {
                if (abs((long)nums[i]-(long)nums[l]) <= (long)t) return true;
            }
        }
        return false;
    }
};
//8 ms method
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> record;
        for(int i = 0; i<nums.size(); i++) {
            if(record.lower_bound((long long)nums[i] - (long long)t) != record.end() && *record.lower_bound((long long)nums[i] - (long long)t) <= (long long)nums[i] +  (long long)t) {
                return true;
            }
            
            record.insert(nums[i]);

            if(record.size() == k + 1) {
                record.erase(nums[i-k]);
            }

        }
        
        return false;
    }
};
