class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int>ans;
		bool found = false;
 		for (int i = 0; i < nums1.size(); i++) {
			found = false;
			for (int j = 0; j < nums2.size(); j++) {
				if (nums1[i] == nums2[j]) {
					nums2[j] = INT_MIN;
					found = true;
				}
			}
			if (found) ans.push_back(nums1[i]);
		}
		return ans;
    }
};
//fatest method
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        //unordered_set<int> uset1;
        unordered_set<int> uset1(nums1.begin(), nums1.end());
        vector<int> result;
        
        //if(nums1.empty() || nums2.empty())return result;
        
        //for(size_t i = 0; i < nums1.size(); i++)
        //{
        //    uset1.insert(nums1[i]);
        //}
        
        for(size_t i = 0; i < nums2.size(); i++)
        {
            unordered_set<int>::iterator it = uset1.find(nums2[i]);
            if(it != uset1.end())
            {
                result.push_back(nums2[i]);
                uset1.erase(it);
            }
        }
        
        return result;
    }
};
