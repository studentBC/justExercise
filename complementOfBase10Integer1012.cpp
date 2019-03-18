class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)return 1;
        int number = 1, count = 0;
        while (number<N) {
            number=number<<1;
            count++;
        }
        //cout << count << endl;
        int ans = 0;
        for (int i = 0; i < count; i++) {
            number = N>>i&1;
            if ( number == 0) {
                //cout << i << " , ";
                ans+=pow(2,i);
            }  
        }
        return ans;
    }
};

