class Solution {
public:
    vector<double> compute(double a, double b) {
        vector<double>ans = {a+b, a-b, b-a, a*b, a/b, b/a};
        return ans;
    }
    bool go(vector<double>& num) {
        if (num.size() == 1) {
            if (abs(num[0]-24.0) < 0.001) return true;
            return false;
        }
        for (int i = 0; i < num.size(); i++) {
            for (int j = i+1; j < num.size(); j++) {
                
                for (double c : compute(num[i], num[j])) {
                    vector<double>next;
                    next.push_back(c);
                    for (int k = 0; k < num.size(); k++) {
                        if (k == j || k == i) continue;
                        next.push_back(num[k]);
                    }
                    if (go(next)) return true;
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>num(cards.begin(), cards.end());
        return go(num);
    }
};
