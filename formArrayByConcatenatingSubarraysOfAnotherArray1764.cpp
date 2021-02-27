class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int start = 0;
        bool found;
        for (int i = 0; i < groups.size(); i++) {
            found = false;
            for (int j = start; j < nums.size(); j++) {
                if (nums[j] == groups[i][0] && groups[i].size() <= nums.size()-start) {
                    //cout <<"enter " << j << endl;
                    found = true;
                    for (int k = j+1, l = 1; l < groups[i].size(); k++, l++) {
                        if (groups[i][l] != nums[k]) {
                            found = false;
                            break;
                        }
                    }
                }
                if (found) {
                    start=j+groups[i].size();
                    break;
                }
            }
            if (!found) return false;
            //else cout <<"found " << i << endl;
        }
        return true;
    }
};
//the fatest solution
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int curr = 0;
        for (int i =0 ; i < nums.size() && curr < groups.size(); ++i) {
            bool valid = true;
            for (int j =0;j<groups[curr].size();++j) {
                if (i+j==nums.size() || nums[i+j]!=groups[curr][j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                i += groups[curr].size() - 1;
                ++curr;
            }
        }
        return curr == groups.size();
    }
};
