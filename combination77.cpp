class Solution {
public:
	void comb (int n, int k, int start, vector<int>&temp, vector<vector<int>>&ans) {
		if (k == 0) {
			ans.push_back(temp);
			return;
		} else {
			for (int i = start; i <= n; i++) {
				temp.push_back(i);
				comb (n, k-1, i+1, temp, ans);
				temp.pop_back();
			}
		}
		return;
	}
    vector<vector<int>> combine(int n, int k) {
		vector<vector<int>>ans;
		vector<int>temp;
		comb (n, k, 1, temp, ans);
		return ans;
    }
};
//the fatest method
class Solution {
public:
    void comb(int n, int k, int i, vector<int> &row, vector<vector<int>> &ans){
        if(i>n+1)
            return;
        
        int p = row.size();
        if(k-p > n+1-i)
            return;
        
        if(row.size()==k){
            ans.push_back(row);
            return;
        }
        
        row.push_back(i);
        comb(n,k,i+1,row,ans);
        row.pop_back();
        comb(n,k,i+1,row,ans);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> row;
        comb(n,k,1,row,ans);
        return ans;
    }
};
