class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>length;
        int sum = 0, end, ans = 0, len;
        nums.push_back(0);
        for (int i: nums) {
            if (i) sum++;
            else {
                if (sum) {
                    length.push_back(sum);
                    sum = 0;
                }
                length.push_back(0);
            }
        }
        //cout << length[length.size()-2] << endl;
        if (length[length.size()-2]+1 == nums.size()) return nums.size()-2;
        //for (int i: length) cout << i <<" , " ;
        end = length.size()-1;
        for (int i = 0; i < end; i++) {
            if (!length[i]) {
                len = 0;
                if (i) {
                    len+=length[i-1];
                }
                if (i+1 < end) {
                    len+=length[i+1];
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
//the 56 ms solution
static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
#define mod 1000000007
class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int sum=0;
        for(auto num : nums)
            sum+=num;
        if(sum==0)   //No way
           return 0; 
        if(sum==nums.size())
        {
           if(nums.size()==1) //No way
              return 0;
           else
              return nums.size()-1; 
        }
       
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
               count++;
            else
            {
               nums[i]=-count;
               count=0; 
            }
        }
        int ans=0;
        count=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==1)
               count++;
            else
            {
               ans=max(ans,count-nums[i]);
               count=0; 
            }
        }
        return ans;
    }
};
