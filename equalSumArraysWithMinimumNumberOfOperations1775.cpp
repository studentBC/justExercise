/*
1. In order to make the two sum's equal, we need either to increase to 6 the numbers in the smaller sum array or decrease to 1 the numbers in the bigger sum array;

2. Since we want to complete the task with minimum operations, it is optimal to choose the greater between the increase and decrease. Hence this is a greedy algorithm.
Note:
If all numbers in an array increasing to 6 still ends up with a sum less than the sum of the other array with all numbers decreasing to 1's, then it is impossible to make their sums equal.
*/
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() <= nums2.size()*6 && nums1.size()*6 >= nums2.size()) {
            int ans = 0, s1 = 0, s2 = 0;
            for (int i: nums1) s1+=i;
            for (int i: nums2) s2+=i;
            if (s1 > s2) swap(nums1, nums2);
            priority_queue <int, vector<int>, greater<int>> q1(begin(nums1), end(nums1));
            priority_queue<int> q2(begin(nums2), end(nums2));
            int diff = abs(s1 - s2);
            while (diff > 0) {
                ++ans;
                if (q1.empty() || (!q2.empty() && q2.top() - 1 > 6 - q1.top())) {
                    diff -= q2.top() - 1;
                    q2.pop();
                } else {
                    diff -= 6 - q1.top();
                    q1.pop();
                }
            }
            return ans;
        }
        return -1;
    }
};
//the 100 ms solution
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), sum1 = 0, sum2 = 0;
        vector<int> cnt1(7, 0), cnt2(7, 0);
        for(int num : nums1){
            sum1 += num;
            cnt1[num]++;
        }
        for(int num : nums2){
            sum2 += num;
            cnt2[num]++;
        }
        if(sum1 == sum2){
            return 0;
        }
        if(6 * m < n || m > 6 * n){
            return -1;
        }
        int ans = 0;
        if(sum2 < sum1){
            swap(sum1, sum2);
            swap(cnt1, cnt2);
        }
        // sum2 > sum1
        for(int i = 1; i <= 6; i++){
            // cout << "i = " << i << ", sum1 = " << sum1 << ", sum2 = " << sum2 << ", ans = " << ans << endl;
            if(sum1 + (6 - i) * cnt1[i] >= sum2){
                return ans + (sum2 - sum1 - 1) / (6 - i) + 1;
            }else{
                sum1 += (6 - i) * cnt1[i];
                ans += cnt1[i];
            }
            if(sum2 - (6 - i) * cnt2[7-i] <= sum1){
                return ans + (sum2 - sum1 - 1) / (6 - i) + 1;
            }else{
                sum2 -= (6 - i) * cnt2[7-i];
                ans += cnt2[7-i];
            }
        }
        return -1;
        
    }
};
