class Solution {
public:
    bool valid (vector<int>& number, int n) {
        int ans = 0;
        for (int i = number.size()-1; i > -1; i--) {
            ans = ans*10+number[i];
        }
        if (ans == n) return false;
        return true;
    }
    int rotatedDigits(int N) {
        int temp, ans = 0, i;
        bool vvalid;
        for (int j = 2; j <= N; j++) {
            vector<int>number;
            vvalid = true;
            i = j;
            while (i) {
                temp = i%10;
                if (temp == 5) {
                    temp = 2;
                } else if (temp == 2) {
                    temp = 5;
                } else if (temp == 6) {
                    temp = 9;
                } else if (temp == 9) {
                    temp = 6;
                }  else if (temp == 0 || temp == 1 || temp == 8) {
                    
                } else {
                    //ans++;
                    vvalid = false;
                    break;
                }
                number.emplace_back(temp);
                i/=10;
                //cout << i <<" , ";
            }
            if (vvalid && valid(number, j)) ans++;
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        int flag = 0;
        for(int i = 1;i<=N;i++){
            int k = i;
            flag = 0;
            while(k>0){
                int p = k%10;
                if(p == 3 || p == 4 || p == 7){
                    flag = 0;
                    break;
                }
                else if(p == 2 || p == 5 || p == 9 || p == 6){
                    flag = 1;
                }
                k = k/10;
            }
            if(flag){
                count++;
            }
        }
        return count;
    }
};
