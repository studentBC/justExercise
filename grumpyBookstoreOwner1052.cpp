class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		int original = 0, increase = 0, most = 0;
  		for (int i = 0; i < X; i++)	{
			if (!grumpy[i]) {
				original+=customers[i];
			} else {
				increase+=customers[i];
			}
		}
		most = increase;
  		for (int i = X, left = 0; i < grumpy.size(); i++, left++)	{
			if (grumpy[left]) {
				increase-=customers[left];
			}
			if (!grumpy[i]) {
				original+=customers[i];
			} else {
				increase+=customers[i];
				most = max (increase, most);
			}
		}
		return original+most;
    }
};
//the 12 ms solution
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        
        
        ios::sync_with_stdio(false);
        int sums = 0, res = 0, max_ = 0, i = 0;
        for(; i < X; i++){
            sums += customers[i]*grumpy[i];
            res += customers[i]*(1-grumpy[i]);
        }
        max_ = sums;
        for(; i< customers.size(); i++){
            sums -= customers[i - X]*grumpy[i - X];
            sums += customers[i]*grumpy[i];
            max_ = max(sums, max_);
            res += customers[i]*(1-grumpy[i]);
        }
        return res + max_;
        
    }
};

