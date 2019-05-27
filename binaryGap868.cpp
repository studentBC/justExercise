class Solution {
public:
    int binaryGap(int N) {
        vector<bool>one(31,false);
        int digit;
        for (int i = 0; i < 31; i++) {
            digit = N>>i;
            if (digit&1 == 1) {
                //cout << i <<" , ";
                one[i] = true;
            }  
        }
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            if (one[i]) {
                for (int j = i+1; j < 31; j++) {
                    if (one[j]) {
                        ans = max (ans, j-i);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int binaryGap(int N) {
        bitset<64> bs(N);
        //cout << bs.to_string() << endl;
        bool bStart = false;
        int nPrev = 0;
        int nMax = 0;
        for(int i = 0; i < 64; i++) {
            if(!bStart && bs[i] == true) {
                bStart = true;
                nPrev = i;
                continue;   //get rid of the case where first 1 bit is the only 1 bit
            }
            
            if(!bStart) {
                continue;
            }
            
            if(bs[i] == true) {
                nMax = max(i - nPrev, nMax);
                nPrev = i;
            }
        }        
        return nMax;
    }
};
