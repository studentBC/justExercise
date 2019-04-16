class Solution {
public:
    void go (int i, int target, vector<vector<int>>& diff, int count, int& max) {
        if (max < count) max = count;
        if (i < diff.size()) {
            for (int b = i+1; b < diff[i].size(); b++) {
                if (diff[i][b] == target) {
                    //cout <<i <<" , "<<b <<" target: " << target << " count: " << count << endl;
                    go (b,target,diff,count+1,max);
                }
            }
        }
    }
    int longestArithSeqLength(vector<int>& A) {
        vector<vector<int>>diff(A.size()-1,vector<int>(A.size(),INT_MAX));
        for (int i = 0; i < A.size(); i++) {
            for (int j = i+1; j < A.size(); j++) {
                diff[i][j] = (A[j]-A[i]);
            }
        }
        int count, max = 0, minus;
        for (int i = 0; i < diff.size(); i++) {
            for (int j = i+1; j < diff[i].size(); j++) {
                count = 1;
                go (j,diff[i][j],diff,1,count);
                if (count > max) max = count;
            }
        }
        return max+1;
    }
};
//60ms method
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector<int> present[20000+5];
        int n = A.size();
        for(int i=0; i<n; ++i){
            present[A[i]].push_back(i);
        }
        int ma = 0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int start = A[i];
                int cd = A[j] - A[i];
                int ans = 2;
                int chek = cd + A[j];
                int ptr = j+1;
                while(true){
                    if( chek < 0 ){ break; }
                    if( present[chek].empty() ){ break; }
                    auto get = lower_bound( present[chek].begin(), present[chek].end(), ptr);
                    if( get == present[chek].end() ){ break; } 
                    ans++;
                    ptr = *get + 1;
                    chek += cd;
                }
                ma = max( ans, ma);
            }
        }
        return ma;
    }
};
