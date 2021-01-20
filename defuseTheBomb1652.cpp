class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans(code.size(), 0);
        if (k == 0) return ans;
        bool change = false;
        if (k < 0) {
            k = -k;
            change = true;
        }
        int b = 0, f = k;

        for (int i = 0; i < k; i++) {
            ans[0] += code[i];
        }
        for (int i = 1; i < code.size(); i++) {
            if (f >= code.size()) f = 0;
            if (b >= code.size()) b = 0;
            ans[i] = ans[i - 1] + code[f] - code[b];
            f++;b++;
        }
        if (!change) {
            f = ans[0];
            ans.erase(ans.begin());
            ans.push_back(f);
        }
        else {
            while (k) {
                f = ans.back();
                ans.pop_back();
                ans.insert(ans.begin(),f);
                k--;
            }
        }
        return ans;
    }
};
