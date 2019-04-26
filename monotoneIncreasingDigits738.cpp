class Solution {
public:
    bool check (vector<int>& digit) {
        for (int i = 1; i < digit.size(); i++) {
            if (digit[i] < digit[i-1]) return true;
        }
        return false;
    }
    int monotoneIncreasingDigits(int N) {
        //if (N%10 == 0) return N-1;
        vector<int>digit;
        int num = N, sum;
        while (num>0) {
            digit.emplace_back(num%10);
            num/=10;
        }
        reverse(digit.begin(), digit.end());
        for (int i = 1; i < digit.size(); i++) {
            if (digit[i] < digit[i-1]) {
                    for (int j = digit.size()-1; j > 0; j--) {
                        if (check(digit)) {          
                            digit[j] = 9;
                            //cout << digit[i-1] << endl;
                            if (digit[j-1] > 0) {
                                digit[j-1]--;
                            } else {
                                int k = j-1;
                                while(k<1) {
                                    digit[k-1] = 10+digit[j-1]-1;
                                }
                                digit[k]--;
                            }   
                        }
                    }   
                    sum = 0;
                    for (int j = 0; j < digit.size(); j++) {
                        //cout << digit[j];
                        sum*=10;
                        sum+=digit[j];
                    }
                    return sum;
            }
            
        }
        return N;
    }
};

