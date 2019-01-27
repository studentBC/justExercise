class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int>ans;
        int max = S.length() , min = 0;
        for (int i = 0; i <= S.size(); i++) {
            if (S[i] == 'D') {
                ans.push_back(max);
                max--;
            } else {
                 ans.push_back(min);
                min++;
            }
            
        }
        return ans;
    }
};
