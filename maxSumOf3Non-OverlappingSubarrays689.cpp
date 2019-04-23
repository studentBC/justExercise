class Solution {
public:
    void go (int start, int k, int sum, vector<int>& temp, vector<int>& accu,  vector<int>& ans, int& maxsum) {
        if (temp.size() == 3) {
            //cout << temp[0] << " , " << temp[1] << " , " <<temp[2] << endl;
            if (sum > maxsum) {
                maxsum = sum;
                ans[0] = temp[0];ans[1] = temp[1];ans[2] = temp[2];
            }
        } else {
            for (int i = start; i < accu.size(); i++) {
                if (temp.empty() || i >= temp.back()+k ) {
                    temp.emplace_back(i);
                    go (start+k, k, sum+accu[i] , temp, accu, ans, maxsum);
                    temp.pop_back();
                }
            }
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        if (k == 1) {
            vector<int>answer;
            int largest = 0, index = 0;
            for (int i = 0; i < 3; i++) {
                largest = 0;
                for (int j = 0; j < nums.size(); j++) {
                    if (largest < nums[j]) {
                        largest = nums[j];
                        index = j;
                    }  
                }
                nums[index] = INT_MIN;
                answer.emplace_back(index);
            }
            sort(answer.begin(), answer.end());
            return answer;
        }

        int sum = 0 , end = nums.size()-k+1, maxsum = 0;
        vector<int>accu(end,0);
        for (int i = 0; i < k; i++) sum+=nums[i];
        accu[0] = sum;
        for (int i = 1; i < end; i++) {
            accu[i] = accu[i-1]-nums[i-1]+nums[i+k-1];
        }
        vector<int>temp;
        vector<int>ans(3,-1);
        go (0 , k, 0, temp, accu, ans, maxsum);
        return ans;
    }
};
/*
The question asks for three non-overlapping intervals with maximum sum of all 3 intervals. If the middle interval is [i, i+k-1], where k <= i <= n-2k, the left interval has to be in subrange [0, i-1], and the right interval is from subrange [i+k, n-1].

So the following solution is based on DP.

posLeft[i] is the starting index for the left interval in range [0, i];
posRight[i] is the starting index for the right interval in range [i, n-1]; 
Then we test every possible starting index of middle interval, i.e. k <= i <= n-2k, and we can get the corresponding left and right max sum intervals easily from DP. And the run time is O(n).

Caution. In order to get lexicographical smallest order, when there are two intervals with equal max sum, always select the left most one. So in the code, the if condition is ">= tot" for right interval due to backward searching, and "> tot" for left interval. Thanks to @lee215 for pointing this out!
*/
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), maxsum = 0;
        vector<int> sum = {0}, posLeft(n, 0), posRight(n, n-k), ans(3, 0);
        for (int i:nums) sum.push_back(sum.back()+i);
       // DP for starting index of the left max sum interval
        for (int i = k, tot = sum[k]-sum[0]; i < n; i++) {
            if (sum[i+1]-sum[i+1-k] > tot) {
                posLeft[i] = i+1-k;
                tot = sum[i+1]-sum[i+1-k];
            }
            else 
                posLeft[i] = posLeft[i-1];
        }
        // DP for starting index of the right max sum interval
        // caution: the condition is ">= tot" for right interval, and "> tot" for left interval
        for (int i = n-k-1, tot = sum[n]-sum[n-k]; i >= 0; i--) {
            if (sum[i+k]-sum[i] >= tot) {
                posRight[i] = i;
                tot = sum[i+k]-sum[i];
            }
            else
                posRight[i] = posRight[i+1];
        }
        // test all possible middle interval
        for (int i = k; i <= n-2*k; i++) {
            int l = posLeft[i-1], r = posRight[i+k];
            int tot = (sum[i+k]-sum[i]) + (sum[l+k]-sum[l]) + (sum[r+k]-sum[r]);
            if (tot > maxsum) {
                maxsum = tot;
                ans = {l, i, r};
            }
        }
        return ans;
    }
};
