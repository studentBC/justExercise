class Solution {
public:
    Solution(vector<int>& nums) {
        srand(time(nullptr));
        for (int i = 0; i < nums.size(); i++) {
            pos.emplace_back(pair<int,int>(nums[i],i));
        }
        sort(pos.begin(),pos.end());
    }
    
    int pick(int target) {
        vector<int>indices;
        for (int i = 0; i < pos.size(); i++) {
            if (pos[i].first == target) {
                indices.emplace_back(pos[i].second);
            } else if (pos[i].first > target) {
                break;
            }
        }
        int size = indices.size();
        size = rand()%size;
        return indices[size];
    }
private:
    vector<pair<int,int>>pos;
}; 

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */ 

/**
 * the fatest method
 */
class Solution {

public:
    vector<int> V;
    int len;

    Solution(vector<int>& nums):V(nums){
        len = nums.size();
        static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
    }

    int pick(int target) {
        int count = 0, result = 0;

        for(int i = 0; i < len; ++i){
            if(V[i] == target){
                ++count;
                if(rand()%count == 0) result = i;
            }
        }

        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
