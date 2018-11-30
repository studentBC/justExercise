class Solution {
public:

    int addDigits(int num) {
		vector<int>digit;
 		while (num>9) {
			while (num>0) {
				digit.push_back(num%10);
				num/=10;
			}
			num = 0;
			for (int i = digit.size()-1; i > -1 ; i--) {
				//cout << digit[i] << " , ";
				num+=digit[i];
				digit.pop_back();
			}
		}
		return num;
    }
};
//fatest method
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num-1) % 9;
    }
};
