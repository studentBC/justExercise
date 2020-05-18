class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        unordered_set<double>num;
        double tmp;
        for (double i = 1; i <= n; i++) {
            for (double j = 1; j < i; j++) {
                tmp = j/i;
                if ( !num.count(tmp)) {
                    num.insert(tmp);
                    ans.push_back(to_string((int)j)+"/"+to_string((int)i));
                } //else break;
            }  
        }
        return ans;
    }
};
//32 ms solution
class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    vector<string> simplifiedFractions(int n) {
        static int cur = 0;
        static vector<vector<string>> prev(101);
        for (int i = cur + 1; i <= n; i++) {
            for (int j = 1; j < i; j++)
                if (gcd(i, j) == 1)
                    prev[i].push_back(to_string(j) + "/" + to_string(i));
        }
        cur = max(cur, n);
        vector<string> res;
        for (int i = 1; i <= n; i++)
            res.insert(res.end(), prev[i].begin(), prev[i].end());
        return res;
    }
};
