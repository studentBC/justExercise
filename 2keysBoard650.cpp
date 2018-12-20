class Solution {
public: 
    int minSteps(int n) {
        vector<int>steps(n+1,0);
        int move;
        for (int i = 2; i <= n; i++) {
            if (i%2 == 0) {
                steps[i] = steps[i/2]+2;
            } else {
                steps[i] = i;
                for (int j = i-1; j>1; j--) {
                    if (i%j == 0) {
                        //cout <<i <<" :  "<< j << endl;
                        move = i/j;
                        steps[i] = steps[j]+move;
                        //cout << move  <<"  " << steps[i] << endl;
                        break;
                    }
                }
            }
        }
        return steps[n];
    }
};
//the fatest method
class Solution {
public:
    int minSteps(int n) {
      int ans = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            while (n%i == 0) {
                ans += i;
                n /= i;
            }
        }
        if (n > 1) ans += n;
        return ans;
    
    }
};
