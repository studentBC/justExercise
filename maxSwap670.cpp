class Solution {
public:
    int maximumSwap(int num) {
        vector<int>nums;
        int temp = num;
        do {
            nums.push_back(temp%10);
            temp/=10;
        }while (temp>0);
        reverse(nums.begin(),nums.end());
        /*
        for (int i = 0; i < nums.size(); i++) {
            cout <<nums[i];
        }*/
        bool changed = false;
        int index , max;
        for (int i = 0; i < nums.size(); i++) {
            //cout <<nums[i];
            max = nums[i];
            for (int j = i+1; j < nums.size(); j++) {
                if (max < nums[j]) {
                    index = j;
                    changed = true;
                    max = nums[j];
                } else if (changed && max == nums[j]) {
                    index = j;
                }
            }
            if (changed) {
                temp = nums[index];
                nums[index] = nums[i];
                nums[i] = temp;
                break;
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = ans*10+nums[i];
        }
        return ans;
    }
};
