class Solution {
public:
    int countTexts(string pressedKeys) {
        long long mod = 1e9+7, len = pressedKeys.size();
        vector< long long> sum(len+1, 0);
        long long s = 0;
        sum[0] = 1;
        int stop;
        for (int i = 1; i <= len; i++) {
            s = sum[i-1]%mod;
            if (pressedKeys[i-1] == '7' || pressedKeys[i-1] == '9') stop = 3;
            else stop = 2;
            for (int j = i-2, k = 0; j > -1 && k < stop; j--, k++) {
                if (pressedKeys[j] == pressedKeys[i-1]) {
                    s+=sum[j];
                    s%=mod;
                } else break;
            }
            sum[i] = s;
            //cout << i << " : " <<s  << endl;
        }
        return sum.back();
    }
};
