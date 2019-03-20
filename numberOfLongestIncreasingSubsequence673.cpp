class Solution {
public:
    void go (int start, int prevCount, int prevNum, int& ans, vector<int>& nums, vector<int>& count, int largest) {
        if (prevCount == largest) {
            ans++;
        } else {
            for (int i = start+1; i < count.size(); i++) {
                if (count[i] == prevCount+1 && nums[i] > prevNum) {
                    go (i,count[i],nums[i],ans,nums,count,largest);
                }
            }
        }
    }
    bool judge (vector<int>count, int start) {
        for (int i = start+1; i < count.size(); i++) {
            if (count[i] > count[start]) return true;
        }
        return false;
    }
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>count(nums.size(),0);
        vector<int>largest(nums.size(),0);
        map<int,int>candidate;
        map<int,int>::iterator it;
        int mc;
        for (int i = 0; i < nums.size(); i++) {
            mc = 0;
            for (int j = i-1; j > -1; j--) {
                if (nums[i] > nums[j]) {
                    mc = count[j]+1;
                    if (count[i] < mc) count[i] = mc;
                    //cout << count[i] <<" , ";
                    //break;
                }
            }
        }   
        //cout << endl;
        int max = 0;
        for (int i = 0; i < count.size(); i++) {
            max = count[i]; 
            for (int j = i+1; j < count.size(); j++) {
                if (max < count[j]) {
                    max = count[j];
                }
            }
            largest[i] = max;
            //cout << largest[i] << " , ";
        }
        int ans = 0;
        for (int i = 0; i < count.size(); i++) {
            if (count[i] == 0 && judge(count,i)) {
                go (i,0, nums[i], ans, nums ,count,largest[0]);
            } else if (!judge(count, i) && i ==0) {
                return count.size();
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:

    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        vector<vector<pair<int, int>>> dyn(nums.size() + 1);
        int max_so_far = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // bsearch insertion point
            int l = 0, r = max_so_far;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (dyn[mid].back().first < nums[i]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            
            // bsearch number of options
            int options = 1;
            int row = l - 1;
            if (row >= 0) {
                int l1 = 0, r1 = dyn[row].size();
                while (l1 < r1) {
                    int mid = l1 + (r1 - l1) / 2;
                    if (dyn[row][mid].first < nums[i]) {
                        r1 = mid;
                    } else {
                        l1 = mid + 1;
                    }
                }
                
                options = dyn[row].back().second;
                options -= (l1 == 0) ? 0 : dyn[row][l1 - 1].second;
            }
            
            
            dyn[l].push_back({nums[i], (dyn[l].empty() ? options : dyn[l].back().second + options)});
            if (l == max_so_far) {
                max_so_far++;
            }
        }
        
        return dyn[max_so_far-1].back().second;
    }
};
