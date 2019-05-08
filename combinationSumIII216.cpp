class Solution {
public:
	void go (int start, int k, int n, int sum, vector<int>& temp, vector<vector<int>>& ans) {
		if (temp.size() == k) {
			if (sum == n) {
				ans.emplace_back(temp);
			}
		} else {
			for (int i = start; i < 10; i++) {
				temp.emplace_back(i);
				go (i+1,k,n,sum+i,temp,ans);
				temp.pop_back();
			}
		}
	}
    vector<vector<int>> combinationSum3(int k, int n) {
 		vector<int>temp;
		vector<vector<int>>ans;
		go (1,k,n,0,temp,ans);
		return ans;
    }
};
