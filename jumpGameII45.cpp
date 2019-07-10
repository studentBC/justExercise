//dp solution which will lead to TLE
class Solution {
public:
    int jump(vector<int>& nums) {
        int* step = new int[nums.size()];
        step[0] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            step[i] = INT_MAX;
            for (int j = i-1; j > -1; j--) {
                if (nums[j] >= i-j) {
                    step[i] = min(step[i],step[j]+1);
                }
            }
        }
        return step[nums.size()-1];
    }
};
//greedy solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int prev = 0, farest = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
			if (i > prev) {
				prev = farest;
				ans++;
			}
            farest = max(farest, i+nums[i]);
        }
        return ans;
    }
};
//4 ms solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int pre = 0, cur = 0, res = 0;
        for(int i = 0; i < n - 1; i++){
            cur = max(cur, nums[i] + i);
            if(pre == i){
                pre = cur;
                res++;
                if(cur >= n - 1) break;
            }
        }
        return res;
    }
};
