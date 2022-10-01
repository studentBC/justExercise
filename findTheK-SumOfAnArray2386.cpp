/*
 Intuition: First find the maximum sum possible. We will get maximum possible sum after adding all the elements greater than 0. Next, if we want to find 2nd maximum sum what we can do?
We can either subtract a smallest positive number from this sum or add largest (minimum(abs(num)) negative number in the sum to get 2nd maximum number.
Similarly, we have to add or subtract numbers from current sum to get next largest sum.
Key: We can convert all the negative numbers to positive and then simply can subtract them instead of adding.
So to get the maximum sum we will store the least values that needs to be subtracted from maxsum in priority queue (minheap).
Time O(nlogn + KlogK)
Space O(K)
 */
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int len = nums.size();
        long long maxSum = 0;
        vector<long long>negative;
        for (int i = 0; i < len; i++) {
            if (nums[i] > -1) maxSum+=nums[i];
            else nums[i] = -nums[i];
        }
        sort(nums.begin(), nums.end());
        //Initialize priority queue (minheap) to store current least value which needs to be
        //subtracted from maxsum and the index of nums we are currently at.
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({nums[0], 0});
        int index;
        long long substr;
        while (!pq.empty() && negative.size() < k-1) {
            index = pq.top().second;
            substr = pq.top().first;
            pq.pop();
            negative.push_back(substr);
            if (index+1 < len) {
                pq.push({substr+nums[index+1], index+1});
                pq.push({nums[index+1]+substr-nums[index] , index+1});
            }
        }
        vector<long long>ans;
        ans.push_back(maxSum);
        for (long long sub: negative) {
            ans.push_back(maxSum-sub);
        }
        return ans.back();
    }
};
