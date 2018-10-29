//fatest method
int static f = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r=numbers.size()-1;
        while(l<r) {
            int sum = numbers[l] + numbers[r];
            if(sum==target) return {l+1, r+1};
            else if(sum<target) l++;
            else r--;
        }
        return {};
    }
};
//my method
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int len = numbers.size();
        int left , sum = 0;
        for (int i = 0; i < len; i++) {
            left = target - numbers[i];
            if (left > -1) {
                ans.push_back(i+1);
                
                for (int j = i+1; j < len; j++) {
                    if (left == numbers[j]) {
                        ans.push_back(j+1);
                    }
                }
                if (ans.size() == 2) {
                    return ans;
                } else {
                    ans.pop_back();
                }
            } else {
               return ans;
            }
        }
        return ans;
    }
};
