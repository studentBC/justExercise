//the fatest method
class Solution {
private:
    bool dfs(vector<int>& nums, int idx, int target) {
        if (target<0) return false;
        if (target==0) return true;
        for (int i=idx; i<nums.size(); i++) {
            if (target-nums[i]<0) break; // trims the dfs since we already sorted nums
            if (dfs(nums,i+1,target-nums[i])) return true;
        }
        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        sort(nums.rbegin(),nums.rend()); // sort the nums
        return sum%2==0 && dfs(nums,0,sum/2);
    }
};
//my method
class Solution {
public:
    void find (vector<int>& nums, int start, int target, bool* ans) {
        target-=nums[start];
        if (target == 0 && start>=0) {
            *ans = true;
            return;
        } else if ( target <0 && start > 0) {
            target+=nums[start];
            find(nums,start-1,target,ans);
        } else if (target > 0 && start > 0){
            find(nums,start-1,target,ans);
        }
        return;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum+=nums[i];
        }       
        //cout << "sum is " << sum << endl;
        if (sum%2!=0)return false;
        int half = sum/2;
        sort(nums.begin(),nums.end());
        int count = -1, end;
        sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum+=nums[i];
            if (sum < half) end = i;
            if (nums[i] < half) {
                count = i;
            } else if (nums[i] == half) {
                return true;
            } else {
                break;
            }
        }
        bool* ans = (bool*)malloc(sizeof(bool));
        *ans = false;
        for (int i = half; i > end; i--) {
            find(nums,i,half,ans);
            if (*ans) return true;
        }
        
        return *ans;
    }
};
