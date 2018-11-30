//fatest method
class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0, n = guess.length();
        int ds[10] = {0},dg[10] = {0};
        for(int i = 0; i < n; i++){
            int x = secret[i] - '0', y = guess[i] - '0';
            if(x == y) a++;
            ds[x]++, dg[y]++;
        }
        for (int i = 0 ; i < 10; i++){
            b += min(ds[i], dg[i]);
        }
        b -= a;
        string ans = to_string(a) + 'A' + to_string(b) + 'B';
        return ans;
    }
};
//my method
class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0 , len;
        string ans;
        if (guess.length() < secret.length()) {
            len = guess.length();
        } else {
            len = secret.length();
        }
        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i]) {
                A++;
                secret[i] = guess[i] = 'f';
            }
        }
        for (int i = 0; i < guess.length(); i++) {
            if (guess[i]!='f') {
                for (int j = 0; j < secret.length(); j++) {
                    if (secret[j]!='f' && secret[j] == guess[i]) {
                        B++;
                        secret[j] = guess[i] = 'f';
                        break;
                    }
                }
            }
        }
        //printf(" %d , %d \n",A,B);
        ans+= to_string(A); 
        ans+= "A";
        ans+=to_string(B);
        ans+="B";
        return ans;
    }

};
