class Solution {
public:
    bool bs (vector<int>& nums, int target, int index) {
        int left = 0, right = nums.size()-1, mid;
        while (left <= right) {
            mid = (left+right)/2;
            if (nums[mid] == target) {
                if (mid != index) {
                    return true;
                } else {
                    if (mid+1 < nums.size() && nums[mid+1] == target) {
                        return true;
                    } else if (mid > 0 && nums[mid-1] == target) {
                        return true;
                    } else {
                        return false;
                    }
                }
            } else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return false;
    }
    int findPairs(vector<int>& nums, int k) {
        if (k < 0 || nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int prev = nums[0]-1, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (prev != nums[i]) {
                if (bs(nums, nums[i]+k, i)) ans++;
            }
            prev = nums[i];
        }
        return ans;
    }
};
//the fatest solution
using namespace std;
auto __ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0 || nums.size() < 1) {
            return 0;
        }
        int result = 0;
        std::unordered_map<int, int> m;
        for (int n:nums) {
            m[n]++;
        }
        for (auto item : m) {
            if ((k == 0 && item.second > 1)|| (k != 0 && m.count(item.first + k))) {
                result++;
            }
        }
        return result;
    }
};
