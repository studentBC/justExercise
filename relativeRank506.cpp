class Solution {
public:
    
    static bool compare(pair<int,int>& a,pair<int,int>& b){
        return a.first>b.first;
    }
    
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int,int>> P;
        for(int i=0;i<nums.size();i++){
            P.push_back(make_pair(nums[i],i));
        }
        sort(P.begin(),P.end(),compare);
        vector<string> ans(nums.size());
        for(int i=0;i<P.size();i++){
            if(i==0) ans[P[i].second]="Gold Medal";
            else if(i==1) ans[P[i].second]="Silver Medal";
            else if(i==2) ans[P[i].second]="Bronze Medal";
            else ans[P[i].second]=to_string(i+1);
        }
        return ans;
    }
};
//my method
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int>temp(nums);
        vector<string>ans;
        sort(temp.begin(), temp.end(), greater<int>());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < temp.size(); j++) {
                if (nums[i] == temp[j]) {
                    if (j == 0) {
                        ans.push_back("Gold Medal");
                    } else if (j == 1) {
                        ans.push_back("Silver Medal");
                    } else if (j == 2) {
                        ans.push_back("Bronze Medal");
                    } else {
                        ans.push_back(to_string(j+1));
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
