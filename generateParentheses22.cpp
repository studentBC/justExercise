class Solution {
public:
    void go (int start, int n, int half, vector<int>&location, vector<string>& ans) {
        if (location.size() == half) {
            vector<char>temp(n,')');
            for (int i = 0; i < location.size(); ++i) temp[location[i]] = '(';
            string strr(temp.begin(), temp.end());
            //cout << strr << endl;
            ans.push_back(strr);
        } else {
            for (int i = start+1; i < n-1; i++) {
                if (location.back()+2 <= 2*location.size()) {
                //if (n-1-location.back() >= 2(n/2-location.size())+1) {
                    location.push_back(i);
                    go (i,n,half,location,ans);
                    location.pop_back();
                }
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<int>location;
        vector<string>ans;
        location.push_back(0);
        int total = n << 1;
        go (0, total, n, location ,ans);
        return ans;
    }
};

