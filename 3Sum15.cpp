class Solution {
public:
    bool isSame (vector<int> nums, vector<vector<int>> ans) {
        int count = 0;
        for (int i = 0; i < ans.size(); i++) {
            count = 0;
            for (int j = 0; j < 3; j++) {
                if (ans[i][j] == nums[j]) {
                    count++;
                } else {
                    break;
                }
            }
            if (count == 3) return true;
        }
        return false;
    }
    void Sum (int start, vector<int> temp, vector<int>& nums, vector<vector<int>>& ans) {
        if (temp.size() == 3) {
            //cout << temp[0] << " , " << temp[1] << " , " << temp[2] << endl;
            if (temp[0]+temp[1]+temp[2] == 0) {
                //sort(temp.begin(),temp.end());
                if (!isSame( temp, ans)) {
                    ans.push_back(temp);
                    return;
                }
            }
            return;
        } else {
            for (int i = start; i < nums.size(); i++) {
                temp.push_back(nums[i]);
                Sum(i+1,temp,nums,ans);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        Sum (0, temp, nums, ans);
        return ans;
    }
};
//fatest metod
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        //sort input nums
        //pick a num(keep its index), find 2SUM for remaining nums
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        
        for(int i = 0; i < n - 2 ; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
               continue;
            int k = -1 * nums[i];
            int start = i + 1;
            int end = n - 1;
            while(start < end)
            {
                int sum = nums[start] + nums[end];
                if(sum < k)
                    start++;
                else if(sum > k)
                    end--;
                else
                {
                    out.push_back(vector<int>{nums[i], nums[start], nums[end]});
                    while(start < end && nums[start+1] == nums[start]) start++;
                    while(start < end && nums[end-1] == nums[end])end--;
                    start++;
                    end--;
                }
            }
        }
        
        return out;
    }
};
