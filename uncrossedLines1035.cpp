class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<int>lines(B.size(), -1);
        vector<pair<int,int>>location;
        int ans = -1 , most;
        for (int i = 0; i < A.size(); i++) {
            location.clear();
            for (int j = 0; j < B.size(); j++) {
                most = -1;
                 if (A[i] == B[j]) {
                     for (int k = j-1; k > -1; k--) {
                         if (lines[k] > most) {
                             most = lines[k];
                             //break;
                         }
                     }
                     if (most < 0) {
                         location.emplace_back(pair<int,int>(j,max( 0, lines[j])));
                         //lines[j] = 0;
                     } else {
                         location.emplace_back( pair<int,int>(j,max(most+1 , lines[j])));
                         //lines[j] = most+1;
                     }
                 }
            }
            for (auto it:location) {
                lines[it.first] = it.second;
            }
        }
        for (auto i:lines) ans = max(ans,i);
        return ans+1;
    }
};

