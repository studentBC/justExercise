class Solution {
public:
    bool find (vector<int>& index, int target) {
        for (int i = 0; i < index.size(); i++) {
            if (target == index[i]) return true;
        }  
        return false;
    }
    void go (vector<int>& nums, vector<int>& index, int sum, int length, bool& found) {
        if (sum == length && !found) {
            for (int i = 0; i < index.size(); i++) {
                //cout  << nums[index[i]] <<" , ";
                nums[index[i]] = -1;
            }
            //cout << endl;
            found = true;
        } else if (!found) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > 0 && sum+nums[i] <= length && !find(index,i)) {
                    index.push_back(i);
                    go (nums,index,sum+nums[i],length,found);
                    index.pop_back();
                }
            }
        }
    }
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int length = 0;
        for (int i = 0; i < nums.size(); i++) {
            length+=nums[i];
        }
        if (length%4 >0) return false;
        length/=4;
        bool found;
        vector<int>index;
        sort(nums.begin(), nums.end(),greater<int>());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == length) {
                nums[i] = -1;
            } else if (nums[i] < length && nums[i] > 0) {
                found = false;
                index.clear();
                index.push_back(i);
                go (nums, index, nums[i], length, found);
                if (!found) return false;
            } else if (nums[i] > length) {
                return false;
            }
        }
        return true;
    }
};

