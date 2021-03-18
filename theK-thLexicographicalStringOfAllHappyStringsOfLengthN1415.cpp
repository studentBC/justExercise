/*
wrong test case:
6
57

2
4
*/
class Solution {
public:
    string getHappyString(int n, int k) {
        vector<int>permu(n);
        long s = 1;
        for (int i = n-1; i > 0; i--) {
            s <<=1;
            permu[i] = s;
        }
        permu[0] = s*3;
        if (permu[0] < k) return "";
        string ans, candidate = "abc";
        int end;
        //n--;
        //int end = n-1;
        //char prev = '$';
        //while (k) {
            for (int i = 0; i < n; i++) {
                if (permu[i] == k) {
                    k-=permu[i];
                    for (int i = 2; i > -1; i--) {
                        if (candidate[i]!=ans.back()) {
                            ans+=candidate[i];
                            break;
                        }
                    }
                } else if (permu[i] < k) {
                    k-=permu[i];
                    for (int i = 2; i > -1; i--) {
                        if (candidate[i]!=ans.back()) {
                            ans+=candidate[i];
                            break;
                        }
                    }
                } else {
                    if (k == 0 || (i+1 < n && permu[i+1] < k)) {
                        if (i+1 < n)  {
                            end = k/permu[i+1];
                            k%=permu[i+1];
                            if (k == 0) end--;
                        }
                        if (i) {
                            for (int i = 2; i > -1; i--) {
                                if (candidate[i]!=ans.back()) {
                                    ans+=candidate[i];
                                    break;
                                }
                            }
                        } else {
                            ans+=candidate[end];
                        }
                    } else {
                        for (int i = 0; i < 3; i++) {
                            if (candidate[i]!=ans.back()) {
                                ans+=candidate[i];
                                break;
                            }
                        }
                    }
                }
            }
        return ans;
        //}
    }
};
//other people's solution
class Solution {
public:
    string getHappyString(int n, int k) {
        backtrack(n, k);
        return k > 0 ? "" : ans;
    }
protected:
    string ans;
    string tmp;
    void backtrack(int n, int& k){
        if(k < 0)
            return;
        if(n == 0){
            if(--k == 0)
                ans = tmp;
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(tmp.size() > 0 && tmp.back() == ch)
                continue;
            tmp.push_back(ch);
            backtrack(n - 1, k);
            tmp.pop_back();
        }
    }
};
