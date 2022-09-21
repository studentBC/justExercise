class Solution {
public:

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int sum = 0, l = -1, r = -1;
        unordered_map<int, int>num;
        vector<int>ans, left, right(s.size(), -1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') sum++;
            else if (s[i] == '|') {
                num[i] = sum;
                l = i;
            }
            left.push_back(l);
        }
        for (int i = s.size()-1; i > -1; i--) {
            if (s[i] == '|') r = i;
            right[i] = r;
        }
        int tmp;
        for (int i = 0; i < queries.size(); i++) {
            if (num[left[queries[i][1]]] < 0 || num[right[queries[i][0]]] < 0
               || (queries[i][1] == queries[i][0])) ans.push_back(0);
            else {
                tmp = num[left[queries[i][1]]] - num[right[queries[i][0]]];
                tmp = max(tmp, 0);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
