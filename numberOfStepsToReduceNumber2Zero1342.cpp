class Solution {
public:
    int numberOfSteps (int num) {
		int ans = 0;
 		while (num) {
			if (num%2 == 0) {
				num = num >> 1;
			} else {
				num--;
			}
			ans++;
		}
		return ans;
    }
};
//the fatest solution

