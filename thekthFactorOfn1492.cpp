class Solution {
public:
    int kthFactor(int n, int k) {
        int mid = sqrt(n), tmp;
        vector<int>factor;
        for (int i = 1; i <= mid; i++) {
            if (n%i == 0) {
                factor.push_back(i);
                tmp = n/i;
                if (tmp != i) factor.push_back(tmp);
            }  
        }
        sort(factor.begin(), factor.end());
        if (k > factor.size()) return -1;
        return factor[k-1];
    }
};
//the fatest solution
class Solution {
public:
	int kthFactor(int n, int k) {
		int num = 0;
		vector<int> factor;
		int i;
		for (i = 1; i <= sqrt(n); i++) {
			if (n % i == 0) {
				num++;
				factor.push_back(n / i);
				if (num == k) {
					return i;
				}
			}
		}
		if (k > 2 * num) {
			return -1;
		}
		if (factor[num - 1] * factor[num - 1] == n) {
			if (k == 2 * num) {
				return -1;
			}
		}
		return factor[2 * num - k];
	}
};
