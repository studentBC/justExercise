class Solution {
public:
	unordered_map<int,int>nc;
	int get (int num) {
		int count = 0, original = num;
		while (num != 1) {
			if (nc.count(num)) {
				count+=nc[num];
				break;
			} else {
				if (num%2) {
					num = num*3+1;
				} else {
					num/=2;
				}
			}
			count++;
		}
		nc[original] = count;
		return count;
	}
    int getKth(int lo, int hi, int k) {
 		vector<pair<int,int>>nums;
		for (int i = lo; i <= hi; i++) {
			nums.push_back(make_pair(get(i), i));
		}
		sort(nums.begin(), nums.end());
		return nums[k-1].second;
    }
};
//8 ms solution
static vector<int> comp;
class Solution {
public:
int compute(int i) {
    if (i < 2)
        return 0;
    return 1 + (i % 2 ? compute(i * 3 + 1) : compute(i / 2));
}
int getKth(int lo, int hi, int k) {
    if (comp.empty()) {
        for (auto i = 0; i <= 1000; ++i)
            comp.push_back(compute(i));
    }
    vector<int> sorted(hi - lo + 1);
    iota(begin(sorted), end(sorted), lo);
    nth_element(begin(sorted), begin(sorted) + k - 1, end(sorted), [](int i, int j) {
        return comp[i] == comp[j] ? i < j : comp[i] < comp[j]; });
    return sorted[k - 1];
}
};
