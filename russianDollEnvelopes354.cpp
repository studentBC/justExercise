class Solution {
public:
    bool static compare (pair<int, int> a, pair<int, int> b) {
        if (a.first == b. first) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> res({nums[0]});
        for (int i = 1; i < nums.size(); ++i) {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end())
                res.push_back(nums[i]);
            else
                *it = nums[i];
        }

        return res.size();
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort (envelopes.begin(), envelopes.end(), compare);
        int prev , count, max = 0;
        vector<int>temp;
        for (int i = 0; i < envelopes.size(); i++) {
            temp.push_back(envelopes[i].second);
        }
         
        return lengthOfLIS(temp);
    }
};
//the fatest method
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<int> res;
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
            if(p1.first == p2.first)
                return p1.second > p2.second;
            else
                return p1.first < p2.first;
        });
        for(int i = 0; i < envelopes.size(); i++) {
            int target = envelopes[i].second;
            int start = 0; 
            int end = res.size() - 1;
            while(start + 1 < end) {
                int mid = start + (end - start) / 2;
                if(res[mid] < target)
                    start = mid;
                else
                    end = mid;
            }
            if(res.empty() || target > res[res.size() - 1])
                res.push_back(target);
            else if(target < res[start])
                res[start] = target;
            else if(target < res[end] && target > res[start])
                res[end] = target;
        }
        return res.size();
    }
};
