class Solution {
public:
     int maxSumMinProduct(vector<int>& nums) {
          int len = nums.size(), mod = 1e9+7;
          vector<int>lb(len), rb(len);
          vector<long>sum(len+1, 0);
          stack<int>st, stmp;
          for (int i = 0; i < len; i++) {
              while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
              if (!st.empty()) lb[i] = st.top()+1;
              else lb[i] = 0;
              st.push(i);
          }
          for (int i = len-1; i > -1; i--) {
              while (!stmp.empty() && nums[stmp.top()] >= nums[i]) stmp.pop();
              if (!stmp.empty()) rb[i] = stmp.top()-1;
              else rb[i] = len-1;
              stmp.push(i);
          }
          for (int i = 0; i < len; i++) {
              sum[i+1] = nums[i]+sum[i];
          }
          long ans = 0;
          for (int i = 0; i < len; i++) {
              ans = max(ans, (sum[rb[i]+1]-sum[lb[i]])*nums[i]);
          }
          return ans%mod;
     }
};
