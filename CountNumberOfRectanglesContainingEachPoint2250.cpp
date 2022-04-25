class Solution {
public:
	int bs (vector<int>& xl, int x) {
		int left = 0, ans = xl.size(), right = ans-1, mid;
		while (left <= right) {
			mid = (left+right)/2;
			if (xl[mid]>=x) {
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		return right;	
	}
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
  		unordered_map<int, vector<int>>h;
		for (int i = 0; i < rectangles.size(); i++) h[rectangles[i][1]].push_back(rectangles[i][0]);
		for (int i = 0; i <= 100; i++) sort(h[i].begin(), h[i].end());
		vector<int>ans;
		int x, y, count;
		for (vector<int>p: points) {
			x = p[0]; y = p[1]; count = 0;
			for (int j = y; j<= 100; j++) {
				if (h.count(j)) ans+=h[j].size()-bs(h[j], x);
			}
			ans.push_back(count);
		}
		return ans;
    }
};
