/*
 * Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]

false case:

[]
1
1

[-2147483648,2147483647]
-2147483648
2147483647

Input: [0,1,3,50,75]
0
99
Expected: ["2","4->49","51->74","76->99"]

[-1]
-2
-1

[-2]
-2
-1
[-1]
-2
0

[1,2]
0
9

[1,1,1]
1
1

 */
class Solution {
public:
        vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string>ans;
        string temp;
        if (nums.size() == 0) {
            if (upper == lower) {
                return {to_string(lower)};
            } else {
                temp = to_string(lower);
                temp+="->";
                temp += to_string(upper);
            }
            return {temp};
        } else if (nums.size() == 1) {
            long n = nums[0], l = lower, u = upper;
            temp = "";
            if (n-l > 1) {
                temp = to_string(l);
                temp+="->";
                temp+=to_string(n-1);
            } else if (n - l == 1) {
                temp = to_string(l);
            }
            if (temp.size() > 0) ans.emplace_back(temp);
            temp = "";
            if (u-n > 1) {
                temp = to_string(n+1);
                temp+="->";
                temp+=to_string(u);
            } else if (u-n == 1) {
                temp = to_string(u);
            }
            if (temp.size() > 0) ans.emplace_back(temp);
            return ans;
        }
        long a,b;
        int end = nums.size()-1;
        if (lower < nums[0]) {
            if (upper != nums[0] && nums[0]-1 != lower) {
                temp = to_string(lower);
                temp+="->";
                temp+=to_string(nums[0]-1);
                ans.emplace_back(temp);
            } else {
                ans.emplace_back(to_string(lower));
            }
        }
        for (int i = 0; i < end; i++) {
            a = nums[i+1];b = nums[i];
            if (a-b <= 1) {
                continue;
            } else if (a-b == 2) {
                ans.emplace_back(to_string(b+1));
            } else {
                temp = to_string(b+1);
                temp+="->";
                temp+=to_string(a-1);
                ans.emplace_back(temp);
            }
        }
        if (upper > nums.back()) {
            if (upper != nums.back()+1 && nums.back()+1 != upper) {
                temp = to_string(nums.back()+1);
                temp+="->";
                temp+=to_string(upper);
                ans.emplace_back(temp);
            } else {
                ans.emplace_back(to_string(upper));
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        // consider the overflow corner case
        long next = lower;
        vector<pair<long,long>> result;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < next) {
                continue;
            }
            
            if (nums[i] == next) {
                next++;
                continue;
            }
            
            result.push_back(make_pair(next, nums[i]-1));
            next = (long)nums[i]+1;
        }
        
        // final check
        if (next <= upper) {
            result.push_back(make_pair(next, upper));
        }
        
        vector<string> ret;
        for (int i = 0; i < result.size(); i++) {
            if (result[i].first == result[i].second) {
                ret.push_back(to_string(result[i].first));
            } else {
                ret.push_back(to_string(result[i].first) + "->" + to_string(result[i].second));
            }
        }
        
        return ret;
    }
};
