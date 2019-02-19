class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max = INT_MIN , sum = 0;
        int end;
        if (nums.size()< k) {
            end = nums.size();
        } else {
            end = k;
        }
        for (int i = 0; i < end; i++) {
            sum+= nums[i];
        }
        if (end == 0) {
            return 0;
        } else if (k >= nums.size()) {
            return sum/k;
        }
        end = k-1;
        for (int i = 0; i < nums.size()-k; i++) {
            if (max < sum) max = sum;
            end++;
            //cout << end << " , ";
            sum-=nums[i];
            sum+=nums[end];      
        }
        if (max < sum) max = sum;
        return max/k;
    }
};

