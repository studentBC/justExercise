class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxKey = 0;
        unordered_map<int, vector<int>> map;
        for (int r = nums.size() - 1; r >= 0; --r) { // The values from the bottom rows are the starting values of the diagonals.
            for (int c = 0; c < nums[r].size(); ++c) {
                map[r + c].push_back(nums[r][c]);
                maxKey = max(maxKey, r + c);
            }
        }
        vector<int> ans;
        for (int key = 0; key <= maxKey; ++key)
            for (int v : map[key]) ans.push_back(v);
        return ans;
    }
};

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
 		unordered_map<int, vector<int>>table;
		int end = 0;
		for (int i = nums.size()-1; i > -1; i--) {
			for (int j = 0; j < nums[i].size(); j++) {
				table[i+j].push_back(nums[i][j]);
				end = max (end, i+j);
			}
		}
		vector<int>ans;
		for (int i = 0; i <= end; i++) {
			for (int j: table[i]) ans.push_back(j);
		}
		return ans;
    }
};

//the fatest solution
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int N = nums.size(), M = 0;
        for(int i = 0; i < N; i++){
            M = max(M, (int) nums[i].size());
        }
        vector<vector<int>> reorder(M+N+1);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < nums[i].size(); j++){
                reorder[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(vector<int>& arr : reorder){
            if(arr.size() > 0){
                reverse(arr.begin(), arr.end());
                ans.insert(ans.end(), arr.begin(), arr.end());
            }
        }
        return ans;
        
    }
};
