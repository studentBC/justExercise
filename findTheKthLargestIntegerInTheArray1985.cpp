class Solution {
public:
    static bool compare (string& a, string& b) {
        if (a.size() == b.size()) {
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == b[i]) continue;
                else return a[i] < b[i];
            }
            return false;
/*
std::sort requires that if comp(a,b)==true, comp(b,a)==false (see https://en.cppreference.com/w/cpp/named_req/Compare)

since you default to returning true when the strings are equal this isn't satisfied, so you should just return false instead
*/
        } else return a.size() < b.size();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), compare);
        return nums[nums.size()-k];
    }
};
