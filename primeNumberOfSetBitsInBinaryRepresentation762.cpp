class Solution {
public:
    bool isPrime (int n) {
        if (n == 1) return false;
        for(int i = 2; i <= n / 2; ++i) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int L, int R) {
        int count = 0, num, temp;
        for (int i = L; i <= R; ++i) {
            //cout << i << endl;
            num = 0;
            for (int j = 0; j < 32; j++) {
                if (i>>j&1 == 1) num++;    
            }
            if (isPrime(num)) {
                count++;
            }
        }
        return count;
    }
};
//the fatest method
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        
        int cnt = 0;
        for(int i = L ; i <= R; ++i){
            int x = __builtin_popcount(i);
            if( isPrime(x) ) ++cnt;
        }
        
        return cnt;
    }
    
private:
    bool isPrime(int num){
        if(num == 2) return true;
        else if(num == 2) return true;
        else if(num == 3) return true;
        else if(num == 5) return true;
        else if(num == 7) return true;
        else if(num == 11) return true;
        else if(num == 13) return true;
        else if(num == 17) return true;
        else if(num == 19) return true;
        return false;
    }
};
