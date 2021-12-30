class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
 		int len = arr.size();
		vector<long long>pre(len, 0), sufix(len, 0), ans(len, 0);
		unordered_map<int, vector<int>>num;
		for (int i = 0; i < len; i++) num[arr[i]].push_back(i);
		for (auto& it: num) {
			for (int i = 1; i < it.second.size(); i++) pre[it.second[i]] = pre[it.second[i-1]]+i*(long)(it.second[i]-it.second[i-1]);
		}
		for (auto& it: num) {
			for (int i = it.second.size()-2; i > -1; i--) sufix[it.second[i]] = sufix[it.second[i+1]]+long(it.second.size()-1-i)*(long)(it.second[i+1]-it.second[i]);
		}
        for (int i = 0; i < len; i++) ans[i]+= pre[i]+sufix[i];
		return ans;
    }
};
