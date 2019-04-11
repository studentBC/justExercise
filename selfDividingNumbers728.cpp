class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
 		vector<int>ans;
		bool contain;
		int temp, num;
		for (int i = left; i <= right; i++) {
			contain = true;
			temp = i;
			while (temp > 0) {
				num = temp%10;
				if (num == 0 || i%num!=0) {
					contain = false;
					break;
				}
				temp/=10;
			}
			if (contain) ans.push_back(i);
		}
		return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        
        for (int num = left ; num <= right ; num++) {
            // break to digits
            int n = num;
            bool self_dividing = true;
            while (n > 0) {
                int digit = n % 10;
                if (digit == 0 || (digit != 0 && (num % digit) != 0)) {
                    self_dividing = false;
                    break;
                }
                n /= 10;
            }
            
            if (self_dividing)
                res.push_back(num);
            
        }
        return res;
        
    }
};
