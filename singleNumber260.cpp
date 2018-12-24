class Solution {
public:
    vector<int>singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }
        vector<int>ans;
        for (auto it: umap) {
            if (it.second < 2) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
//fatest method 

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    // Let a and b are the solo numbers respectively.
    int a = 0, b = 0, c = 0;
    // Find c = a ^ b.
    for (int n : nums) c ^= n;
    int lowbit = c & -c;
    
    for (int n : nums) {
      if (lowbit & n) {
        a ^= n;
      } else {
        b ^= n;
      }
    }
    
    return {a, b};
  }
};
