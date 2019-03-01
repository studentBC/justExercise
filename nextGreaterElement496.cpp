class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int,int>bigger;
        vector<int>ans;
        bool found = true;
        for (int i = 0; i < nums.size(); i++) {
            found = false;
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    bigger.insert(pair<int,int>(nums[i],nums[j]));
                    found = true;
                    break;
                }
            }
            if (!found)bigger.insert(pair<int,int>(nums[i],-1));
        }
        for (int i = 0; i < findNums.size(); i++) {
            ans.push_back(bigger.find(findNums[i])->second);
        }
        return ans;
    }
};
