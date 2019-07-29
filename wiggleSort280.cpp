/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example:

Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]
*/
class Solution {
	public:
		void wiggleSort(vector<int>& nums) {
			vector<int>temp(nums.begin(), nums.end());
			sort(temp.begin(), temp.end());
			int j = 0, start;
			for (int i = 0; i < nums.size(); i+=2) {
				nums[i] = temp[j];
				j++;
			}
			if (nums.size()%2) {
				start = nums.size()-2;
			} else {
				start = nums.size()-1;
			}
			for (int i = start; i > -1; i-=2) {
				nums[i] = temp[j];
				j++;
			}
			return;
		}
};
//the fatest method
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++)
        {
            if(i%2==1)
            {
                if(nums[i]<nums[i-1])
                    swap(nums[i], nums[i-1]);
            }
            else
            {
                if(nums[i]>=nums[i-1])
                    swap(nums[i], nums[i-1]);
            }
        }
    }
};
