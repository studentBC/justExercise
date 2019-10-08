class Solution {
public:
    void generate (int N, int low, int high, vector<int>& tmp, unordered_set<int>& ans) {
        if (tmp.size() == N) {
            int sum = 0;
            if (N == 10) {
                //for (int i:tmp) cout << i;
                //cout << endl;
                int limit[]={2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
                for (int i = 0; i < 10; i++) {
                    if (limit[i]<tmp[i]) {
                        return;
                    } else if (limit[i] > tmp[i]) {
                        break;
                    }
                }
            }

            for (int i =0; i < N; i++) {
                sum = sum*10+tmp[i];
                if(sum > high)break;
            }
            if (sum>= low && sum <= high) ans.insert(sum);
            return;
        }
        for (int i = 0; i < 10; i++) {
            if (tmp.empty() || abs(tmp.back()-i) == 1) {
                tmp.emplace_back(i);
                generate ( N, low, high, tmp, ans);
                tmp.pop_back();
            }
        }
    }
    vector<int> countSteppingNumbers(int low, int high) {
        unordered_set<int>ans;
        int l = 0, h =0, temp;
        temp = low;
        while (temp) {
            temp/=10;
            l++;
        }
        temp = high;
        while (temp) {
            temp/=10;
            h++;
        }
        for (int i = l; i <= h; i++) {
            vector<int>tmp;
            generate(i, low, high, tmp, ans);
        }
        vector<int>answer(ans.begin(), ans.end());
        sort(answer.begin(), answer.end());
        return answer;
    }
};

//the fatest solution
class Solution {
public:
    
    long long pow10[11];
    
    void solve(int index, int prev, int num, int low, int high, int len, vector<int>&ans) {
        // 0111
        // 100000
        // cout << index << " " << prev << " " << num << " " << len <<endl;
        long long maxm = (long long)num*pow10[len-index] + (pow10[len-index]-1);
        long long minm = (long long)num*pow10[len-index];
        if (minm > high or maxm < low) return;
        
        if (index == len) {
            if (num >= low and num <= high) ans.push_back(num);
            return;
        }
        
        for(int i=0; i<10; i++) {
            if (prev == -1) {
                if (i == 0) solve(index+1, -1, num, low, high, len, ans);
                else solve(index+1, i, num*10 + i, low, high, len, ans);
            } else if (i == (prev + 1) or i == (prev - 1)) {
                solve(index+1, i, num*10+i, low, high, len, ans);
            }
        }
    }
    
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int>ans;
        int len = 0;
        int highC = high;
        while(highC) {
            len++;
            highC/=10;
        }
        pow10[0] = 1LL;
        for(int i=1; i<11; i++) pow10[i] = pow10[i-1]*10LL;
        
        solve(0, -1, 0, low, high, len, ans);
        return ans;
    }
};
