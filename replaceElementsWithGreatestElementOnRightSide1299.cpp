class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
		int big;
 		for (int i = 0; i < arr.size(); i++) {
			big = 0;
			for (int j = i+1; j < arr.size(); j++) {
				big = max(big, arr[j]);
			}
			arr[i] = big;
		}
		arr.back() = -1;
		return arr;
    }
};
//the fatest solution
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for (int i = arr.size() - 1, mx = -1; i >= 0; i--) {
            int t = arr[i];
            arr[i] = mx;
            mx = max(mx, t);
        }
        return arr;
    }
};
