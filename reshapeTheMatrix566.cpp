class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
 		if (nums.size()*nums[0].size() != r*c)return nums;
		vector<int>number;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums[i].size(); j++) {
				number.push_back(nums[i][j]);
			}
		}
		vector<vector<int>>ans;vector<int>temp;
		int count = 0;
		for (int i = 0; i < r; i++) {
			temp.clear();
			for (int j = 0;j < c; j++) {
				temp.push_back(number[count]);
				count++;
			}
			ans.push_back(temp);
		}
		return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) 
    {
        vector<vector<int>> ret_vec(r,vector<int>(c,0));
        if(nums.size() * nums[0].size() != r * c)
        {
            return nums;
        }
        int rowPointer = 0;
        int colPointer = 0;
        for(int i = 0; i < nums.size(); i ++)
        {
            for(int j = 0; j < nums[i].size(); j++)
            {
                if(colPointer >= c)
                {
                    colPointer = 0;
                    rowPointer ++;
                }
                ret_vec[rowPointer][colPointer] = nums[i][j];
                colPointer ++;
            }
        }


        return ret_vec;
        
    }
};
