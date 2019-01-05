class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //if (nums.size() == 3 && nums[2] == INT_MIN && nums[0] == 1 && nums[1] == 2) return -2147483648;
        bool enter = false;
        int first  = INT_MIN, second = INT_MIN, third = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > first) first = nums[i];
        }
        if (nums.size() < 3) return first;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < first && nums[i] > second) second = nums[i];
        }
        //cout << second;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < second && nums[i] >= third) {
                enter = true;
                third = nums[i];
            }
        }
        if (!enter) return first;
        return third;
    }
};
//the fatest method
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // set is ordered.
        set<int> m;
        
        for (int n : nums) {
            // insert if we have less then 3 or if |n| is bigger than the smallest.
            if (m.size() < 3 || n > *m.begin()) m.insert(n);
            // if we have more then 3 remove the smallest.
            if (m.size() > 3) m.erase(m.begin());
        }
        
        return m.size() == 3 ? *m.begin() : *m.rbegin();
    }
};
