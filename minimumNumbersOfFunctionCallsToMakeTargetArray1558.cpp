class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        bool found = true;
        while (found) {
            found = false;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i]%2) {
                    nums[i]--;
                    ans++;
                }
                if (nums[i]) found = true;
            }
            for (int i = 0; i < nums.size(); i++) {
                nums[i] >>=1;
            }
            if (found)ans++;
        }
        
        return ans;
    }
};
//24 ms solution
class Solution {
public:
     int minOperations(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
        
        int turns = 0;
        int nMax = 0;
        for (auto& n : nums)
        {
            nMax = max(n, nMax);
            while (n != 0)
            {
                turns += n & 1;
                n >>= 1;
            }
        }
        while (nMax > 1)
        {
            turns += 1;
            nMax >>= 1;
        }
        
        return turns;
    }

};
