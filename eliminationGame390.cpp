class Solution {
public:
    int lastRemaining(int n) {
		if (n < 3) return n;
		vector<int>temp;
		for (int i = 1; i <= n; i++) {
			temp.push_back(i);
		}
		int count = 0;
		while (n>1) {
			if (count %2 == 0) {
				for (int i = 0; i < temp.size(); i+=2) {
					temp[i] = INT_MAX;
					n--;
				}
				for (int i = 0; i < temp.size(); i++) {
					if (temp[i] == INT_MAX) temp.erase(temp.begin()+i);
				}
			} else {
				for (int i = temp.size()-1; i > -1; i-=2) {
					temp[i] = INT_MAX;
					n--;
				}
				for (int i = 0; i < temp.size(); i++) {
					if (temp[i] == INT_MAX) temp.erase(temp.begin()+i);
				}
			}
			count++;
		}
		return temp[0];
    }
};
