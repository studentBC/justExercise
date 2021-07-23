class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int>count;
        int len = nums.size();
        if (nums[0] == 0) count[0] = 2;
        else count[-nums[0]] = count[nums[0]] = 1;
        for (int i = 1; i < len; i++) {
            unordered_map<int, int>temp;
            for (auto& it: count) {
                temp[it.first+nums[i]] += count[it.first];
                temp[it.first-nums[i]] += count[it.first];
            }
            count = temp;
        }
        return count[target];
    }
};
//the fatest solution
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(),sum=0,s1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        //cout<<sum;
        s1=target+sum;
        if(s1%2!=0)
            return 0;
        s1=s1/2;
        int t[n+1][s1+1];
        //cout<<s1;
        for(int j=0;j<s1+1;j++){
            t[0][j] = 0;
        }
        for(int i=0;i<n+1;i++){
            t[i][0] = 1;
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<s1+1;j++){
                if(nums[i-1]<=j)
                    t[i][j] = t[i-1][j-nums[i-1]]+t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][s1];
        
    }
};
