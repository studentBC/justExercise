class Solution {
public:
    int check (int x, int y, vector<vector<int>>& A, vector<vector<int>>& B) {
        int count = 0;
        for (int i = x,k=0; i < B.size(); i++,k++) {
            for (int j = y,l=0; j < B[i].size(); j++,l++) {
                if (B[i][j] == A[k][l]) {
                    if (A[k][l] == 1) count++;
                }
            }   
        }  
        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ans = 0;

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                ans = max(ans,check(i,j,A,B));
                //cout << "( " << i <<" , " << j <<" ) " << ans << endl;
            }
        }
        for (int i = 0; i < B.size(); i++) {
            for (int j = 0; j < B[i].size(); j++) {
                ans = max(ans,check(i,j,B,A));
                //cout << "( " << i <<" , " << j <<" ) " << ans << endl;
            }
        }

        return ans;
    }
};
//the fatest method
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> Abits, Bbits;
        toBitset(A, Abits);
        toBitset(B, Bbits);

        int r = A.size(), c = A[0].size();
        int res = comp(Abits, Bbits, r, c);
        // shift to left and up can be done by this way
        // res = max(res, comp(Bbits, Abits, r, c));
        return res;
    }

    int comp(vector<int>& Abits, vector<int>& Bbits, int r, int c) {
        int res = 0;
        for (int i = -(r - 1); i < r; i++) {
            for (int j = -(c - 1); j < c; j++) {
                int total = 0;
                for (int k = 0; k < r; k++) {
                    int i1 = i > 0? i : 0, i2 = i < 0? -i : 0;
                    if (k + i1 >= r || k + i2 >= r) continue;
                    int j1 = j > 0? j : 0, j2 = j < 0? -j : 0;
                    int val = (Abits[k + i1] >> j1) & (Bbits[k + i2] >> j2);
                    total += bitset<30>(val).count();
                }
                res = max(res, total);
            }
        }
        return res;
    }

    void toBitset(const vector<vector<int>>& A, vector<int>& res) {
        for (int i = 0; i < A.size(); i++) {
            int val = 0;
            for (int j = 0; j < A[i].size(); j++) {
                val <<= 1;
                val += A[i][j];
            }
            res.push_back(val);
            // cout<<val<<" ";
        }
        // cout<<endl;
    }
};
