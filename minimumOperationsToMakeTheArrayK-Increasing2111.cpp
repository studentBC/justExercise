class Solution {
public:
	int longestNonDecreasingSubseq (vector<int>& temp) {
		vector<int>sub;
		int j, index;
		for (int i = 0; i < temp.size(); i++) {
			j = temp[i];
			if (sub.empty() || sub.back() <= j) sub.push_back(j);
			else {
				index = upper_bound(sub.begin(), sub.end(), j)-sub.begin();
				sub[index] = j;
			}
		}
		return sub.size();
	}
    int kIncreasing(vector<int>& arr, int k) {
  		int len = arr.size(), ans = 0;
		for (int i = 0; i < k; i++) {
			vector<int>temp;
			for (int j = i; j < len; j+=k) {
				temp.push_back(arr[j]);
			}
			ans+=(temp.size() - longestNonDecreasingSubseq(temp));
		}
		return ans;
    }
};
