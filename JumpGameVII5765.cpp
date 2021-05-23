class Solution {
public:
    bool canReach(string s, int a, int b) {
        int n = s.size(), cnt0 = 0;
        if(s[n-1] == '1'){
            return false;
        }
        if(maxConsecutive(s, '1') < b){
            return true;
        }
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur == n - 1){
                return true;
            }
            for(int i = cur + a; i <= min(cur + b, n - 1); i++){
                if(s[i] == '0'){
                    q.push(i);
                }
            }
        }
        return false;
    }
private:
    int maxConsecutive(const string& s, char c) {
        int len = 0, n = s.size(), prev = 0, i = 0;
        while(i < n){
            while(i < n && s[i] == c){
                i++;
            }
            len = max(len, i - prev);
            prev = i + 1;
            i++;
        }
        return len;
    }
};
