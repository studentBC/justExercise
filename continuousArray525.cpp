class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int>accu(nums.size());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum+=nums[i];
            accu[i] = sum;
            //cout << accu[i] <<" , ";
        }
        //cout << endl;
        int max = 0,start = nums.size();
        if (start%2 == 1) {
            start--;
        }
        //cout << start << endl;
        for (int i = start; i >1; i-=2) {
            for (int j = 0; j <= nums.size()-i; j++) {
                //accu[j+i-1]-accu[j];
                if (j<1) {
                    sum = accu[j+i-1];
                } else {
                    sum = accu[j+i-1]-accu[j-1];
                }
                //cout <<"start at: " << j <<" end at " << j+i-1 << " sum: " << sum << endl;
                if (i>>1 == sum) {
                    if (max < i) max = i;
                    break;
                }
            }
            if (max>0)return max;
        }
        return max;
    }
};
//the fatest method
class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {    
        if (nums.size() == 0)
        {
            return 0;
        }

        vector<int> sums(nums.size(), 0);
        vector<int> indexes(nums.size() + 2, -1);
        sums[0] = nums[0] == 0 ? -1 : 1;
        int min = sums[0];
        int maxLng = 0;
        int indexCount = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            sums[i] = sums[i - 1] + (nums[i] == 0 ? -1 : 1);
            if (sums[i] < min)
            {
                min = sums[i];
            }

            ++indexCount;
            if (sums[i] == 0 && indexCount > maxLng)
            {
                maxLng = indexCount;
            }
        }

        min = min < 0 ? -min : 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (indexes[sums[i] + min] == -1)
            {
                indexes[sums[i] + min] = i;
            }
            else
            {
                int lng = i - indexes[sums[i] + min];
                if ((lng % 2) == 0 && lng > maxLng)
                {
                    maxLng = lng;
                }
            }
        }

        return maxLng;
    }
};
