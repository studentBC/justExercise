class Solution {
public:
        void go (int start, int num, int count, vector<int>& ans, int total, int low, int high) {
            if (count == total) {
                if (num >= low && num <= high) ans.push_back(num);
                return;
            }  
            for (int i = start; i < 10; i++) {
                if (i == num%10+1 || num == 0) {
                    num = num*10+i;
                    //cout << num <<" , ";
                    go (i+1, num, count+1, ans, total, low, high);
                    num/=10;
                }
            }
        }
        int getDigit(int number) {
            int count = 0;
            while (number) {
                number/=10;
                count++;
            }
            return count;
        }
        vector<int> sequentialDigits(int low, int high) {
            int lo = getDigit(low); 
            int hi = getDigit(high);    
            //cout << lo <<" , "<<hi;
            vector<int>ans;
            for (int i = lo; i <= hi; i++) {
                go (1, 0, 0, ans, i, low, high);
            }
            return ans;
        }

};
