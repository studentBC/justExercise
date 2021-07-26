class Solution {
public:
    int nextGreaterElement(int n) {
        int number = n;
        vector<int>num;
        while (number) {
            num.emplace_back(number%10);
            number/=10;
        }
        vector<int>nums(num.begin(), num.end());
        reverse(num.begin(), num.end());
        //for (int i = 0; i < num.size(); i++) cout << num[i];
        //cout << endl;
        sort(nums.begin(), nums.end());
        long decimal, sum; bool greater;
        do {
            //for (int i = 0; i < nums.size(); i++) cout << nums[i];
            //cout << endl;
            greater = false;
            for (int i = 0; i < num.size(); i++) {
                if (nums[i] > num[i]) {
                    greater = true;break;
                } else if (nums[i] == num[i]) {
                    continue;
                } else {
                    break;
                }
            }
            if (greater) {
                sum = 0;
                decimal = 1;
                for (int i = nums.size()-1; i > -1; i--) {
                    sum += nums[i] * decimal;
                    decimal *= 10;
                }
                if (sum > INT_MAX) return -1;
                //cout << sum << endl;
                return sum;
            }
        } while ( std::next_permutation(nums.begin() , nums.end()) );
        return -1;
    }
};
//the fatest solution
class Solution {
public:
    int nextGreaterElement(int n) {
        
        string num = to_string(n);
        vector<int>stk;
        string next = ""; bool hasNext = false;
        for(int i = num.size() - 1;i >=0;i--) {
            if(!stk.empty() && num[i] < num[stk.back()]) {
                int j = -1;
                while(!stk.empty() && num[i] < num[stk.back()]) {
                     j = stk.back();stk.pop_back();
                }
                swap(num[i],num[j]); string part2 = num.substr(i+1);
                reverse(part2.begin(),part2.end());
                next = num.substr(0,i + 1) + part2; 
                hasNext = true;
                break;
            }
            stk.push_back(i);
        }
        long res = 0;
        if(!hasNext)
            return -1;
        for(int i = 0;i < next.size();i++) {
            res = res * 10 + next[i] - '0';
            if(res>INT_MAX || res < INT_MIN)
                return -1;
        }
        return res;
    }
};
//beat 88.3 with others concept
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int>ans(len, -1), s;
        int length = len << 1;
        for (int i = 0; i < length; i++) {
            while (!s.empty() && nums[i%len] > nums[s.back()]) {
                ans[s.back()] = nums[i%len];
                s.pop_back();
            }
            s.push_back(i%len);
        }
        return ans;
    }
};
