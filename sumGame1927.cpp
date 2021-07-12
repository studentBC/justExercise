class Solution {
public:
    bool sumGame(string num) {
        int len = num.size(), hl = len/2;
        double sl = 0, sr = 0;
        for (int i = 0; i < hl; i++) {
            if (num[i]=='?') sl+=4.5;
            else sl+=num[i]-'0';
        }
        for (int i = hl; i < len; i++) {
            if (num[i]=='?') sr+=4.5;
            else sr+=num[i]-'0';
        }
        return sr != sl;
    }
};
