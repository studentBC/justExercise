class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        if (nums.size() == 0) {
            return ans;
        } else if (nums.size() < 3) {
            if (nums.size() >=2 && nums[nums.size()-1] == nums[nums.size()-2]) {
                        nums.pop_back();
            }
            return nums;
        }
        int exceed = nums.size()/3;
        sort(nums.begin(),nums.end());
        int prev = nums[0] , count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (prev == nums[i]) {
                count++;
                if (count>exceed) {
                    ans.push_back(nums[i]);
                    //cout << nums[i] << endl;
                    if (ans.size() >=2 && ans[ans.size()-1] == ans[ans.size()-2]) {
                        ans.pop_back();
                    }
                }
            } else {
                count = 1;
            }  
            prev = nums[i];
        }
        return ans;
    }
};
//the fatest mtehod
class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int f=INT_MAX, s=INT_MAX,c1=0,c2=0,i;
        vector<int> as;
        for(i=0;i<a.size();i++)
        {
            if(f==a[i])
                c1++;
            else if(s==a[i])
                c2++;
            else if(c1==0)
            {
                c1++;
                f=a[i];
            }
            else if(c2==0)
            {
                c2++;
                s=a[i];
            }
            else 
            {
                c1--;
                c2--;
            }
        }
        c1=0;
        c2=0;
        for(i=0;i<a.size();i++)
        {
            if(f==a[i])
                c1++;
            else if(s==a[i])
                c2++;
        }
        if(c1>a.size()/3 && c2>a.size()/3)
        {
            as.push_back(f);
            as.push_back(s);
        }
        else if(c1>a.size()/3)
            as.push_back(f);
        else if(c2>a.size()/3)
            as.push_back(s);
        
        return as;
    }
};
