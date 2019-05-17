class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int>acc;
        int sum = nums[0], end = nums.size()-2, zero = 0;
        if (nums[0] == 0) zero++;
        acc.emplace_back(sum);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) zero++;
            sum+=nums[i];
            if (k!=0 && sum%k == 0) return true;
            acc.emplace_back(sum);
        }
        if(k == 0) {
            if ( zero > 1) {
				int count = 0;
				for (int i :nums) {
					if (i == 0) {
						count++;
					} else {
						count = 0;
					}
					if (count > 1) return true;
				}
            }
            return false;
        }
        for (int i = 0; i < end; i++) {
            for (int j = i+2; j < nums.size(); j++) {
                if ((acc[j] - acc[i])%k == 0) return true;
            }
        }
        return false;
    }
};
//16ms method
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> m;
        int sum = 0, last = 0;
        
        for (int n : nums) {
            sum = (k == 0? sum + n : (sum + n) % k);
            if (m.count(sum))    return true;
            m.insert(last);
            last = sum;
        }
        
        return false;
    }
};
