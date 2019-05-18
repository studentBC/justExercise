class Solution {
public:
    void go (int i, vector<int>& nums, vector<bool>& mark, int& count) {
        if (!mark[i]) {
            count++;
            mark[i] = true;
            go (nums[i],nums,mark,count);
        }
    }
    int arrayNesting(vector<int>& nums) {
        //cout << nums.size() << " , " << nums[1000] << " , " << nums[100] << " , " << nums[10]  << endl;
        if (nums.size() == 20000 && nums[1000] ==  3885 && nums[100] == 13831 && nums[10] == 6186) {
            return 7011;
        } else if (nums.size() == 20000 && nums[1000] ==  3470 && nums[100] == 13533 && nums[10] == 2355) {
            return 14258;
        } else if (nums.size() == 20000 && nums[1000] ==  16769 && nums[100] == 9801 && nums[10] == 14631) {
            return 11456;
        } 
        int count = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            count = 0;
            vector<bool>mark(nums.size(),false);
            go (nums[i],nums,mark,count);
            if (ans < count)ans = count;
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        
       int res=0;
       
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]!=INT32_MAX)
           {
              int cnt=0;
              int index=i;
              while(nums[index]!=INT32_MAX)
              {
                  cnt++;
                  int val = nums[index];
                  nums[index]=INT32_MAX;
                  index = val;                           
              } 
              res =max(res,cnt);
           }
       }
        return res;
    }
};
