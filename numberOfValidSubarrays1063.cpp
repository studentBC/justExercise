class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (nums[i] <= nums[j]) ans++;
                else break;
            }
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    int validSubarrays(const vector<int>& a) {
        int res = 0;
        if(a.empty())
            return 0;

        stack<int> memo;
        for(int e : a) {
            while(!memo.empty() && memo.top() > e)
                memo.pop();
            memo.push(e);
            res += (int)memo.size();
        }
        
        return res;
    }
};
