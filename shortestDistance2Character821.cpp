class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int>ans(S.size(),0);
        int left , right;
        for (int i = 0; i < S.size(); i++) {
            right = left = INT_MAX;
            if (S[i]!=C) {
                //search right
                for (int j = i+1; j < S.size(); j++) {
                    if (S[j] == C) {
                        right = j;
                        break;
                    }
                }
                if (right!=INT_MAX)right-=i;
                //search left
                for (int j = i-1; j >-1; j--) {
                    if (S[j] == C) {
                        left = j;
                        break;
                    }
                }
                if (left!=INT_MAX)left = i-left;
                //cout << left <<" , " << right << endl;
                ans[i] = (left<right)?left:right;
            }
        }
        return ans;
    }
};
