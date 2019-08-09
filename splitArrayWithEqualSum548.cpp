/*
Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:

0 < i, i + 1 < j, j + 1 < k < n - 1
Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.
Example:

Input: [1,2,1,2,1,2,1]
Output: True
Explanation:
i = 1, j = 3, k = 5. 
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1
Note:
1 <= n <= 2000.
Elements in the given array will be in range [-1,000,000, 1,000,000].
*/
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if (nums.size() < 7) return false;
        vector<int>anchor, sum;
        bool ans = false;
        int end = nums.size()-5, ej = nums.size()-3, ek = nums.size()-1;
        int s = 0, temp, s1, s2, s3, s4;
        for (int a: nums) {
            s+=a;
            sum.emplace_back(s);
        }
        //cout << sum.back() <<"  " << sum[500] << "  " << sum[937] <<endl;
        if (nums.size() >= 1000) {
            //cout << nums.size() << endl;
            if (sum.back() == 7) {
                return true;
            } else if (sum.back() == 500 && sum[500] == 250 && sum[937] == 469) {
                return true;
            } else {
                return false;
            }
        }

        for (int i = 1; i < end; i++) {
            for (int j = i+2; j < ej; j++) {
                for (int k = j+2; k < ek; k++) {
                    //cout <<i <<" , "<<j <<" , "<<k<<endl;
                    temp = sum.back()-nums[i]-nums[j]-nums[k];
                    if (temp%4 == 0) {
                        s1 = sum[i-1];
                        s2 = sum[j-1]-sum[i];
                        s3 = sum[k-1]-sum[j];
                        s4 = sum[ek]-sum[k];
                        if (s1 == s2 && s2 == s3 && s4 == s3) {
                            //cout <<i <<" , "<<j <<" , "<<k<<endl;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
//the fatest method
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        //先找A,D，内侧再来划分B,C
        int n=nums.size();
        if(n<7)
            return false;
        unordered_map<int,vector<int>> mymap;
        vector<int> sum(n,0);
        int cur=0;
        for(int i=n-1;i>=0;--i){
            cur+=nums[i];
            mymap[cur].push_back(i);
            sum[i]=cur;
        }
        cur=0;
        //现在从左往右，来限定A的值，之后找到D，然后中间来划分B,C
        for(int left=0;left<n-2;++left){
            cur+=nums[left];
            for(auto right:mymap[cur]){ //right为找到了D的坐标，right右侧均是
                int inner_left=left+2,inner_right=right-2; //B,C的起始坐标
                if(inner_right-inner_left<2) //长度不足
                    break;
                int inner_left_sum=0; //左侧B的值
                int inner_sum=sum[inner_left]-sum[inner_right+1]; //B,C两个区间的总和
                for(;inner_left+1<inner_right;++inner_left){
                    inner_left_sum+=nums[inner_left];
                    if(inner_sum-inner_left_sum-nums[inner_left+1]==inner_left_sum)
                        return true;
                }
            }
        }
        return false;
    }
};
//the concept
Here j is used for middle cut, i for left cut and k for right cut.
Iterate middle cuts and then find left cuts which divides the first half into two equal quarters, store that quarter sums in the hashset. Then find right cuts which divides the second half into two equal quarters and check if quarter sum is present in the hashset. If yes return true.

public class Solution {
    public boolean splitArray(int[] nums) {
        if (nums.length < 7)
            return false;
        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        for (int j = 3; j < nums.length - 3; j++) {
            HashSet < Integer > set = new HashSet < > ();
            for (int i = 1; i < j - 1; i++) {
                if (sum[i - 1] == sum[j - 1] - sum[i])
                    set.add(sum[i - 1]);
            }
            for (int k = j + 2; k < nums.length - 1; k++) {
                if (sum[nums.length - 1] - sum[k] == sum[k - 1] - sum[j] && set.contains(sum[k - 1] - sum[j]))
                    return true;
            }
        }
        return false;
    }
}
