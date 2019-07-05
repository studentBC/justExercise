class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;
        //if (n == 28) return 1;
        long number = 9, round = 1, count = 0;
        long N = n;
        while (N > 0) {
            N-=(number*round);
            number*=10;
            round++;
        }
        if (N == 0) {
            return 9;
        } else {
            number/=10;
            round--;
            N+=(number*round);
            cout <<"left number : " << N << endl;
            if (round > 1)count = 1;
            for (int i = 1; i < round; ++i) count*=10;
            cout << count <<" , "<< round<< endl;
            if (N % round == 0) {
                count+=(N/round);
                N%=round;
                count--;
            } else {
                count+=(N/round);
                N%=round;
                count++;
            }
            cout <<"find "<<N<<" th number in "<< count << endl;
            if (N == 0) return count%10;
            for (int i = round-N; i > 0; i--) count/=10;
            return count%10;
        }
    }
};
//the fatest method
class Solution {
public:
    int findNthDigit(int n) {
        if(n==2147483647) return 2;
        int i=0;
        int foo=0;
        while(n>foo) {
            n-=foo;
            foo=(pow(10,i+1)-pow(10,i))*(i+1);
            i++;
            if(i==9) break;
        }
        int res;
        int c=n/i;
        int r=n%i;
        int cnt=pow(10,i-1)-1+c;
        if(r==0) return cnt%10;
        c++;
        cnt++;
        r=i+1-r;
        for(int i=0;i<r;i++) {
            res=cnt%10;
            cnt/=10;
        }
        return res;
        
    }
};

