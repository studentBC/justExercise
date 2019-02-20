class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
 		sort(nums.begin(), nums.end());
		vector<int>ans;
		int prev = INT_MAX, sum = 0, repeat, cs = (1+nums.size())*nums.size()/2;
		for (int i = 0; i < nums.size(); i++) {
			if (prev == nums[i]) {
				repeat = prev;
			}
			sum+=nums[i];
			prev = nums[i];
		}
		sum-=repeat;
		ans.push_back(repeat);
		ans.push_back(cs-sum);
		return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        int arr[n+1] = {0};
        vector<int> idx;
        for(int i = 0; i < n; i++)
        {
            arr[nums[i]]++;
            if(arr[nums[i]] > 1)
                idx.push_back(nums[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            if(arr[i] == 0)
            {
                idx.push_back(i);
                return idx;
            }
        }
        return idx;
    }
};
