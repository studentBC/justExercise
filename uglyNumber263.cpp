class Solution {
public:
    bool isUgly(int num) {
        //int limit = sqrt(num);
        if (num == 1) {
            return true;
        } else if(num == 0) {
            return false;
        } else if (num < 0) {
            return false;
        }
		int prev = num;
		while (num > 1) {
			if (num%2 == 0) {
				num/=2;
			} else if (num%3 == 0) {
				num/=3;
			} else if (num%5 == 0) {
				num/=5;
			}
			if (prev == num) return false;
			prev = num;
		}
		return true;
    }
};
//the fatest method
class Solution {
public:
    bool isUgly(int num) {
        if(num > 1){
            while(num%2==0) num /= 2;
            while(num%3==0) num /= 3;
            while(num%5==0) num /= 5;
        }
        
        if(num == 1) return true;
        else return false;
    }
};
