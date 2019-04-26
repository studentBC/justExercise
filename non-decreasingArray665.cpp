/*
 * test data
 * [3,4,2,3]
 * [2,3,3,2,4]
 */
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0, index = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                count++;
                index = i;
                if (count > 1) return false;
            }
        }
        if (count == 1 && index > 1 && index+1 < nums.size()) {
            if (nums[index-2] <= nums[index] ) {
                return true;
            } else if (nums[index] >= nums[index-1]) {
                return true;
            } else if (nums[index+1] >= nums[index-1]) {
                return true;
            } else {
                return false;
            }
        }
        return true;
    }
};
//the fates method
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int cnt = 0;                                                                   
      ios::sync_with_stdio(false);
      cin.tie(0);
        for(int i = 1; i < nums.size() && cnt<=1 ; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
                if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1] of a priority
                else nums[i] = nums[i-1];                                                //have to modify nums[i]
            }
        }
        return cnt<=1;
      
    }
};
