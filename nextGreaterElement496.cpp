//monotonic stack problem
/*Key observation:
Suppose we have a decreasing sequence followed by a greater number
For example [5, 4, 3, 2, 1, 6] then the greater number 6 is the next greater element for all previous numbers in the sequence

We use a stack to keep a decreasing sub-sequence, whenever we see a number x greater than stack.peek() we pop all elements less than x and for all the popped ones, their next greater element is x
For example [9, 8, 7, 3, 2, 1, 6]
The stack will first contain [9, 8, 7, 3, 2, 1] and then we see 6 which is greater than 1 so we pop 1 2 3 whose next greater element should be 6
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>greater;
        vector<int>s, ans;
        for (int i : nums2) {
            while (!s.empty() && s.back() < i) {
                greater[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        for (int i : nums1) {
            if (greater.count(i)) ans.push_back(greater[i]);
            else ans.push_back(-1);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int,int>bigger;
        vector<int>ans;
        bool found = true;
        for (int i = 0; i < nums.size(); i++) {
            found = false;
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    bigger.insert(pair<int,int>(nums[i],nums[j]));
                    found = true;
                    break;
                }
            }
            if (!found)bigger.insert(pair<int,int>(nums[i],-1));
        }
        for (int i = 0; i < findNums.size(); i++) {
            ans.push_back(bigger.find(findNums[i])->second);
        }
        return ans;
    }
};
