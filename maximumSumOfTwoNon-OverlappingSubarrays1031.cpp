class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<long long>sum;
        long long s = 0;
        for (int i: nums) {
            s+=i;
            sum.push_back(s);
            //cout << s <<", ";
        }
        long long len = nums.size()-firstLen, s1 = 0, s2 = 0, end, ans = 0, back = 0;
        for (int i = 0; i <= len; i++) {
            if (i) s1 = sum[i+firstLen-1] - sum[i-1];
            else s1 = sum[firstLen-1];
            //get front
            back = s2 = 0;
            end = i-secondLen+1;
            for (int j = 0; j < end; j++) {
                if(j) s2 =max(s2, sum[j+secondLen-1]-sum[j-1]);
                else s2 =max(sum[j+secondLen-1], s2);
            }
            //get back
            end = nums.size()-secondLen;
            for (int j = i+firstLen; j <= end; j++) {
                if(j) back =max(back, sum[j+secondLen-1]-sum[j-1]);
                else back = max(back, sum[j+secondLen-1]);
            }
            //cout << s1 <<" : " << max(s2, back) << endl;
            ans = max(ans, s1+max(s2, back));
            
        }
        return ans;
    }
};
