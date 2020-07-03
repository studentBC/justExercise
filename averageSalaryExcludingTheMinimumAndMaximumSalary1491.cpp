class Solution {
public:
    double average(vector<int>& salary) {
 		long long sum = 0;
		int small = INT_MAX, big = INT_MIN;
		for (int s: salary) {
			small = min(s, small);
			big = max (s, big);
			sum+=s;
		}
		sum-=small;
		sum-=big;
		return sum/(double)(salary.size()-2);
    }
};
